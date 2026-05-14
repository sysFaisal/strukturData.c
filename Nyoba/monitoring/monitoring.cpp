#include <cstring>
#include <locale.h>
#include <ncursesw/ncurses.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <chrono>
#include <cstdio>
#include <string>
#include <thread>
#include <vector>

using namespace std;

// =====================================================
// PERSISTENT ADB SHELL
// =====================================================

struct AdbShell
{
    FILE   *in;
    FILE   *out;
    pid_t   pid;
};

AdbShell open_adb_shell()
{
    int pipe_in[2], pipe_out[2];

    pipe(pipe_in);
    pipe(pipe_out);

    pid_t pid = fork();

    if (pid == 0)
    {
        int devnull = open("/dev/null", O_WRONLY);

        dup2(pipe_in[0],  STDIN_FILENO);
        dup2(pipe_out[1], STDOUT_FILENO);
        dup2(devnull,     STDERR_FILENO);

        close(pipe_in[1]);
        close(pipe_out[0]);
        close(devnull);

        execlp("adb", "adb", "shell", nullptr);
        exit(1);
    }

    close(pipe_in[0]);
    close(pipe_out[1]);

    AdbShell shell;
    shell.in  = fdopen(pipe_in[1],  "w");
    shell.out = fdopen(pipe_out[0], "r");
    shell.pid = pid;

    return shell;
}

void close_adb_shell(AdbShell &shell)
{
    fputs("exit\n", shell.in);
    fflush(shell.in);
    fclose(shell.in);
    fclose(shell.out);
    waitpid(shell.pid, nullptr, 0);
}

// =====================================================
// GET DATA — 1 COMMAND, 1 CONNECTION
// =====================================================

void get_adb_data(AdbShell      &shell,
                  float         &cpu_temp,
                  float         &gpu_temp,
                  float         &skin_temp,
                  vector<float> &freqs)
{
    // =====================================================
    // SINGLE BATCH COMMAND
    // =====================================================

    static const char *cmd =
        "dumpsys hardware_properties; "
        "for cpu in /sys/devices/system/cpu/cpu[0-9]*; do "
        "name=$(basename $cpu); "
        "freq=$(cat $cpu/cpufreq/scaling_cur_freq 2>/dev/null || echo 0); "
        "echo \"$name $(( freq / 1000 ))\"; "
        "done; "
        "echo '---END---'\n";

    fputs(cmd, shell.in);
    fflush(shell.in);

    char buffer[256];

    while (fgets(buffer, sizeof(buffer), shell.out))
    {
        // =====================================================
        // END MARKER
        // =====================================================

        if (strstr(buffer, "---END---"))
            break;

        int   core;
        float mhz;

        // =====================================================
        // CPU TEMP
        // =====================================================

        if (strstr(buffer, "CPU temperatures"))
        {
            sscanf(
                buffer,
                "CPU temperatures: [%f]",
                &cpu_temp
            );
        }

        // =====================================================
        // GPU TEMP
        // =====================================================

        else if (strstr(buffer, "GPU temperatures"))
        {
            sscanf(
                buffer,
                "GPU temperatures: [%f]",
                &gpu_temp
            );
        }

        // =====================================================
        // SKIN TEMP
        // =====================================================

        else if (strstr(buffer, "Skin temperatures"))
        {
            sscanf(
                buffer,
                "Skin temperatures: [%f]",
                &skin_temp
            );
        }

        // =====================================================
        // CPU FREQ
        // =====================================================

        else if (sscanf(buffer,
                        "cpu%d %f",
                        &core,
                        &mhz) == 2)
        {
            if (core >= 0 &&
                core < (int)freqs.size())
            {
                freqs[core] = mhz;
            }
        }
    }
}

// =====================================================
// DRAW GRAPH
// =====================================================

void draw_graph(int section,
                const char *title,
                const vector<float> &history)
{
    int total_height =
        (LINES - 4) / 3;

    int start_y =
        2 + (section * total_height);

    int graph_top =
        start_y + 2;

    int graph_bottom =
        start_y + total_height - 3;

    int graph_height =
        graph_bottom - graph_top;

    int graph_left = 11;

    int graph_width =
        COLS - graph_left - 4;

    float min_temp = 20.0f;
    float max_temp = 90.0f;

    // =====================================================
    // TITLE
    // =====================================================

    attron(COLOR_PAIR(4) | A_BOLD);

    mvprintw(
        start_y,
        1,
        "╭─ %s ",
        title
    );

    for (int i = 15; i < COLS - 2; i++)
        printw("─");

    attroff(COLOR_PAIR(4) | A_BOLD);

    // =====================================================
    // CURRENT TEMP
    // =====================================================

    if (!history.empty())
    {
        float current =
            history.back();

        int temp_color = 3;

        if (current >= 80)
            temp_color = 1;

        else if (current >= 50)
            temp_color = 2;

        attron(
            COLOR_PAIR(temp_color) |
            A_BOLD
        );

        mvprintw(
            start_y,
            25,
            "%.2fC",
            current
        );

        attroff(
            COLOR_PAIR(temp_color) |
            A_BOLD
        );
    }

    // =====================================================
    // Y AXIS
    // =====================================================

    for (int i = 0; i <= 5; i++)
    {
        float temp =
            max_temp -
            ((max_temp - min_temp) / 5.0f) * i;

        int y =
            graph_top +
            ((graph_height * i) / 5);

        attron(COLOR_PAIR(4));

        mvprintw(
            y,
            1,
            "%2.0fC ┤",
            temp
        );

        attroff(COLOR_PAIR(4));
    }

    // =====================================================
    // PARTIAL BLOCKS
    // =====================================================

    const char *partial[] =
    {
        " ",
        "⣀",
        "⣄",
        "⣆",
        "⣇",
        "⣧",
        "⣷",
        "⣿"
    };

    // =====================================================
    // HISTORY START
    // =====================================================

    int begin = 0;

    if (history.size() > graph_width)
    {
        begin =
            history.size() - graph_width;
    }

    // =====================================================
    // DRAW GRAPH
    // =====================================================

    for (size_t i = begin;
         i < history.size();
         i++)
    {
        int x =
            graph_left +
            (i - begin);

        float temp =
            history[i];

        if (temp < min_temp)
            temp = min_temp;

        if (temp > max_temp)
            temp = max_temp;

        float normalized =
            (temp - min_temp) /
            (max_temp - min_temp);

        // tinggi graph exact
        float exact_height =
            normalized * graph_height;

        int full_blocks =
            (int)exact_height;

        float fractional =
            exact_height - full_blocks;

        // =====================================================
        // COLOR
        // =====================================================

        int color = 3;

        if (temp >= 80)
            color = 1;

        else if (temp >= 50)
            color = 2;

        attron(COLOR_PAIR(color));

        // =====================================================
        // DRAW FULL BODY
        // =====================================================

        for (int h = 0;
             h < full_blocks;
             h++)
        {
            int y =
                graph_bottom - h;

            mvprintw(
                y,
                x,
                "⣿"
            );
        }

        // =====================================================
        // DRAW TOP SMOOTH PART
        // =====================================================

        int partial_level =
            fractional * 7.0f;

        if (partial_level > 0)
        {
            int y =
                graph_bottom - full_blocks;

            mvprintw(
                y,
                x,
                "%s",
                partial[partial_level]
            );
        }

        attroff(COLOR_PAIR(color));
    }

    // =====================================================
    // BOTTOM BORDER
    // =====================================================

    attron(COLOR_PAIR(4));

    mvprintw(
        graph_bottom + 1,
        7,
        "└"
    );

    for (int i = 8;
         i < COLS - 2;
         i++)
    {
        printw("─");
    }

    attroff(COLOR_PAIR(4));
}

// =====================================================
// MAIN
// =====================================================

int main()
{
    setlocale(LC_ALL, "");

    initscr();

    noecho();

    cbreak();

    curs_set(0);

    nodelay(stdscr, TRUE);

    start_color();

    use_default_colors();

    init_pair(1, COLOR_RED, -1);
    init_pair(2, COLOR_YELLOW, -1);
    init_pair(3, COLOR_GREEN, -1);
    init_pair(4, COLOR_WHITE, -1);

    // Buka 1 koneksi ADB, dipakai selama program jalan
    AdbShell adb = open_adb_shell();

    vector<float> cpu_history;
    vector<float> gpu_history;
    vector<float> skin_history;

    vector<float> cpu_freqs(8, 0);

    float cpu  = 0;
    float gpu  = 0;
    float skin = 0;

    while (true)
    {
        int ch = getch();

        if (ch == 'q')
            break;

        // 1 call, 1 koneksi, semua data sekaligus
        get_adb_data(
            adb,
            cpu,
            gpu,
            skin,
            cpu_freqs
        );

        cpu_history.push_back(cpu);
        gpu_history.push_back(gpu);
        skin_history.push_back(skin);

        int max_history =
            COLS - 20;

        if (cpu_history.size() > max_history)
        {
            cpu_history.erase(cpu_history.begin());
            gpu_history.erase(gpu_history.begin());
            skin_history.erase(skin_history.begin());
        }

        clear();

        // =====================================================
        // HEADER
        // =====================================================

        attron(
            COLOR_PAIR(4) |
            A_BOLD
        );

        mvprintw(
            0,
            2,
            "ANDROID REALTIME MONITOR"
        );

        attroff(
            COLOR_PAIR(4) |
            A_BOLD
        );

        // =====================================================
        // CPU CLOCKS
        // =====================================================

        int x = 35;

        for (int i = 0;
             i < cpu_freqs.size();
             i++)
        {
            int color = 3;

            if (cpu_freqs[i] >= 2000)
                color = 1;

            else if (cpu_freqs[i] >= 1200)
                color = 2;

            attron(COLOR_PAIR(color));

            mvprintw(
                0,
                x,
                "c%d:%.0fMHz",
                i,
                cpu_freqs[i]
            );

            attroff(COLOR_PAIR(color));

            x += 14;
        }

        // =====================================================
        // DRAW ALL GRAPH
        // =====================================================

        draw_graph(
            0,
            "CPU TEMP",
            cpu_history
        );

        draw_graph(
            1,
            "GPU TEMP",
            gpu_history
        );

        draw_graph(
            2,
            "SKIN TEMP",
            skin_history
        );

        // =====================================================
        // FOOTER
        // =====================================================

        attron(COLOR_PAIR(4));

        mvprintw(
            LINES - 1,
            2,
            "[ Q ] Quit"
        );

        attroff(COLOR_PAIR(4));

        refresh();

        this_thread::sleep_for(
            chrono::milliseconds(2000)
        );
    }

    // Tutup koneksi ADB saat keluar
    close_adb_shell(adb);

    endwin();

    return 0;
}
