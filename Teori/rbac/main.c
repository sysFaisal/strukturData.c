#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

#define max 20
/*
#include "model/admin.h"
#include "model/user.h"
#include "dashboard/dashboard.h"
*/
typedef struct 
{
    int x;
    int y;
}Player;

void fill(char map[][max]){
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            map[i][j] = '.'; // isi map
        }
    }
};

void init (Player *p1){
    p1->x = 1;
    p1->y = 1;
};

void draw(Player p1, char map[][max]){
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            if (i == p1.y && j == p1.x){
                map[i][j] = '2';    
            } else {
                map[i][j] = '_';
            }
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
};

int main(){
    char input;
    char map[max][max];
    fill(map);
    Player p1 = {0};
    int test = 0;
    init(&p1);

    do
    {    
        if (test == 0){
            draw(p1, map);
        };
        //Sleep(500);
        input = getch();
        switch (input)
        {
            case 'w':
                p1.y = p1.y - 1;
                if (p1.y < 0){
                    p1.y = max - 1;
                };
                system("cls");
                draw(p1, map);
                test = 1;
                break;

            case 'a':
                p1.x = p1.x - 1;
                if (p1.x < 0){
                    p1.x = max - 1;
                };
                system("cls");
                draw(p1, map);
                test = 1;
                break;

            case 's':
                p1.y = p1.y + 1;
                if (p1.y >= max){
                    p1.y = 0;
                };
                system("cls");
                draw(p1, map);
                test = 1;
                break;

            case 'd':
                p1.x = p1.x + 1;
                if (p1.x >= max){
                    p1.x = 0;
                };
                system("cls");
                draw(p1, map);
                test = 1;
            break;
            
            
            default:
                break;
        }

    } while (input != 'q' && input != 'Q');
    
    printf("Program selesai\n");
};