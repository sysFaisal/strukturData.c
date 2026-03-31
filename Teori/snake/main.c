#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
/*
#include "model/admin.h"
#include "model/user.h"
#include "dashboard/dashboard.h"
*/
#define max1 10

typedef struct{
    int x;
    int y;
} NewHead;

typedef struct Snake {
    int x;
    int y;
    struct Snake *next;
} Snake;

typedef struct {
    int x;
    int y;
    int Cond;
} Point;

typedef struct {
    int atas;
    int kanan;
    int bawah;
    int kiri;
}Direc;

void initHead(Snake **Head, Snake *New){
    New->x = 10;
    New->y = 10;
    New->next = NULL;
    *Head = New;
};

void insertHead(Snake **Head, int x, int y){
    Snake *New = (Snake *)malloc(sizeof(Snake));

    if (*Head == NULL){
        initHead(Head, New);
        return;
    };

    New->x = x;
    New->y = y;
    New->next = *Head;

    *Head = New;
};

void moveD(Snake **Head){
    Snake *Curr = *Head;
    Snake *Prev = NULL;

    if (Curr->next == NULL){
        Curr->x = (*Head)->x + 1;
        Curr->y = (*Head)->y;
        *Head = Curr;
        return;
    };

    while (Curr->next != NULL){
        Prev = Curr;
        Curr = Curr->next;
    };

    Prev->next = NULL;
    
    Curr->x = (*Head)->x + 1;
    Curr->y = (*Head)->y;
    Curr->next = *Head;
    
    *Head = Curr;
    return;
};

void moveA(Snake **Head){
    Snake *Curr = *Head;
    Snake *Prev = NULL;

    if (Curr->next == NULL){
        Curr->x = (*Head)->x + 1;
        Curr->y = (*Head)->y;
        *Head = Curr;
        return;
    };

    while (Curr->next != NULL){
        Prev = Curr;
        Curr = Curr->next;
    };

    Prev->next = NULL;
    
    Curr->x = (*Head)->x - 1;
    Curr->y = (*Head)->y;
    Curr->next = *Head;
    
    *Head = Curr;
    return;
};

void moveS(Snake **Head){
    Snake *Curr = *Head;
    Snake *Prev = NULL;

    if (Curr->next == NULL){
        Curr->x = (*Head)->x + 1;
        Curr->y = (*Head)->y;
        *Head = Curr;
        return;
    };

    while (Curr->next != NULL){
        Prev = Curr;
        Curr = Curr->next;
    };

    Prev->next = NULL;
    
    Curr->x = (*Head)->x;
    Curr->y = (*Head)->y + 1;
    Curr->next = *Head;
    
    *Head = Curr;
    return;
};

void moveW(Snake **Head){
    Snake *Curr = *Head;
    Snake *Prev = NULL;

    if (Curr->next == NULL){
        Curr->x = (*Head)->x + 1;
        Curr->y = (*Head)->y;
        *Head = Curr;
        return;
    };

    while (Curr->next != NULL){
        Prev = Curr;
        Curr = Curr->next;
    };

    Prev->next = NULL;
    
    Curr->x = (*Head)->x;
    Curr->y = (*Head)->y - 1;
    Curr->next = *Head;
    
    *Head = Curr;
    return;
};

void fill(char map[][max1]){
    for (int i = 0; i < max1; i++) {
        for (int j = 0; j < max1; j++) {
            map[i][j] = '.'; // isi map
        }
    }
};

void draw(Snake **Head, char map[][max1], Point *fruit){
    Snake *Temp = NULL;

    for (int i = 0; i < max1; i++) {
        for (int j = 0; j < max1; j++) {

            Temp = *Head;
            int found = 0; // penanda

            while (Temp != NULL){
                if (i == Temp->y && j == Temp->x){
                    found = 1;
                    break;
                }
                Temp = Temp->next;
            }

            if (found){
                map[i][j] = '2';
            } else {
                map[i][j] = '_';
            }

            if (fruit->Cond == 1){
                if (i == fruit->y && j == fruit->x){
                    map[i][j] = 'F';
                }
            };

            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void dropfruit(char map[][max1], Point *fruit){

    if (fruit->Cond == 0){
        do {
            fruit->x = rand() % max1;
            fruit->y = rand() % max1;
        } while (map[fruit->x][fruit->x] == '2');
        fruit->Cond = 1;
    };

}

void logic(Snake **Head, Point *fruit, char direc){
    Snake *Temp = *Head;

    if (Temp->x == fruit->x && Temp->y == fruit->y){
        if (direc == 'w'){
            insertHead(Head, Temp->x, Temp->y - 1);
        } else if (direc == 'a'){
            insertHead(Head, Temp->x - 1 , Temp->y);
        } else if (direc == 's'){
            insertHead(Head, Temp->x, Temp->y + 1);
        } else if (direc == 'd'){
            insertHead(Head, Temp->x + 1 , Temp->y);
        } else {
            return;
        }
        fruit->Cond = 0;
    };
};

int main (){
    Snake *Head = NULL;
    NewHead W = {0};
    Point fruit = {0};

    insertHead(&Head, 0 , 0);
    for (int i = 0 ; i < 5 ; i++){
        insertHead(&Head, Head->x + 1 , Head->y);
    };
    
    char map[max1][max1];
    fill(map);
    int test = 0;
    char input;

    do {
        if (test == 0){
            dropfruit(map, &fruit);
            draw(&Head, map, &fruit);
        };

        input = getch();
        switch (input)
        {
            case 'w':
                moveW(&Head);
                if (Head->y < 0){
                    Head->y = max1 - 1;
                };
                dropfruit(map, &fruit);
                logic(&Head, &fruit, 'w');
                system("cls");
                draw(&Head, map, &fruit);
                test = 1;
                break;

            case 'a':
                moveA(&Head);
                if (Head->x < 0){
                    Head->x = max1 - 1;
                };
                dropfruit(map, &fruit);
                logic(&Head, &fruit, 'a');
                system("cls");
                draw(&Head, map, &fruit);
                test = 1;
                break;

            case 's':
                moveS(&Head);
                if (Head->y >= max1){
                    Head->y = 0;
                };
                dropfruit(map, &fruit);
                logic(&Head, &fruit, 's');
                system("cls");
                draw(&Head, map, &fruit);
                test = 1;
                break;

            case 'd':
                moveD(&Head);
                if (Head->x >= max1){
                    Head->x = 0;
                };
                dropfruit(map, &fruit);
                logic(&Head, &fruit, 'd');
                system("cls");
                draw(&Head, map, &fruit);
                test = 1;
            break;
            
            
            default:
                break;
        }
    } while (input != 'q' && input != 'Q');

    printf("Program selesai\n");

    getchar();
    getchar();
};

/*

void init (Player *p1){
    p1->x = 1;
    p1->y = 1;
};


int main1(){
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
*/