#include "boolean.h"
#include "point.h"
#include "line.h"
#include <stdio.h>
#include <conio.h>

int main() {
    Line L1, L2, L3;
    POINT P1, P2, P3, P4;
    
    P1.x = 0; P1.y = 0;
    P2.x = 4; P2.y = 4; // Garis L1: Gradien 1
    
    P3.x = 2; P3.y = 0;
    P4.x = 6; P4.y = 4; // Garis L2: Gradien 1 (Sejajar dengan L1)

    printf("--- Test Create & Cetak ---\n");
    CreateLINE2(&L1, P1, P2);
    CreateLINE2(&L2, P3, P4);
    
    printf("L1: "); CetakLine(L1); printf("\n");
    printf("L2: "); CetakLine(L2); printf("\n");


    printf("\n--- Test Gradien & Sejajar ---\n");
    printf("Gradien L1: %d\n", GetGradient(L1));
    printf("Gradien L2: %d\n", GetGradient(L2));
    
    if (IsSejajar(L1, L2)) {
        printf("Hasil: L1 dan L2 SEJAJAR (Benar)\n");
    } else {
        printf("Hasil: L1 dan L2 TIDAK SEJAJAR (Salah)\n");
    }

    printf("\n--- Test Tegak Lurus ---\n");
    POINT P5 = {0, 4}, P6 = {4, 0}; 
    CreateLINE2(&L3, P5, P6); // Gradien: (0-4)/(4-0) = -1
    
    printf("L3: "); CetakLine(L3); printf(" | Gradien: %d\n", GetGradient(L3));
    
    if (IsTegakLurus(L1, L3)) {
        printf("Hasil: L1 dan L3 TEGAK LURUS (Benar)\n");
    } else {
        printf("Hasil: L1 dan L3 TIDAK TEGAK LURUS (Salah)\n");
    }

    printf("\n--- Test Geser ---\n");
    printf("L1 sebelum geser (deltaX=2, deltaY=3): "); CetakLine(L1); printf("\n");
    GeserLine(&L1, 2, 3);
    printf("L1 sesudah geser: "); CetakLine(L1); printf("\n");


    getchar();
    getchar();
    getchar();
    return 0;
}