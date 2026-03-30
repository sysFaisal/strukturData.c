#include "boolean.h"
#include "point.h"
#include "line.h"
#include <stdio.h>
#include <conio.h>

int main() {
Line L1, L2, L3, L4;
    int dx, dy;

    printf("Masukkan nilai L1 (x1 y1 x2 y2): \n");
    BacaLine(&L1);
    printf("Nilai L1 = "); CetakLine(L1); printf("\n");

    printf("\nMasukkan nilai pergeseran (dx dy): \n");
    printf("Geser X : "); scanf("%d", &dx);
    printf("Geser Y : "); scanf("%d", &dy);
    L2 = L1; 
    GeserLine(&L2, dx, dy);
    printf("Nilai L2 (L1 digeser) = "); CetakLine(L2); printf("\n");

    POINT P1, P2;
    CreatePOINT2(&P1, 0, 0);
    CreatePOINT2(&P2, 5, 0);
    CreateLINE2(&L3, P1, P2);
    printf("Nilai L3 (Sumbu X) = "); CetakLine(L3); printf("\n");

    L4 = L1; 
    printf("Nilai L4 = "); CetakLine(L4); printf("\n");

    printf("\nPengecekan Posisi Sumbu\n");
    if (IsLOnSbX(L1)) printf("L1 terletak pada Sumbu X\n");
    if (IsLOnSbY(L1)) printf("L1 terletak pada Sumbu Y\n");

    printf("\nPengecekan Relasi L1 dan L2\n");
    if (IsEQLine(L1, L2)) 
        printf("L1 sama dengan L2\n");
    if (IsNEQLine(L1, L2)) 
        printf("L1 tidak sama dengan L2\n");
    if (IsSejajar(L1, L2)) 
        printf("L1 sejajar dengan L2\n");
    if (IsTegakLurus(L1, L2)) 
        printf("L1 tegak lurus dengan L2\n");

    printf("\n Relasi L1 dan L3 (Sumbu X)\n");
    if (IsSejajar(L1, L3)) {
        printf("L1 sejajar dengan L3\n");
    } else if (IsTegakLurus(L1, L3)) {
        printf("L1 tegak lurus dengan L3\n");
    } else {
        printf("L1 tidak sejajar dan tidak tegak lurus dengan L3\n");
    };
        

    printf("\nRelasi L1 dan L4\n");
    if (IsEQLine(L1, L4)) {
        printf("L1 sama dengan L4\n");
    } else {
        printf("L1 berbeda dengan L4\n");
    }

    getchar();
    getchar();
    return 0;
}