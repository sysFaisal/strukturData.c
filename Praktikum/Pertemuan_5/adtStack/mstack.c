/* Program : mstack.c
Author : 2550081098, Faisal Fajari
Kelas : E
Deskripsi: Main Driver file dari prototype stack
Tanggal : 
*/
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "stack.h"

int main() {
    Stack S;
    infotype x;
    int pilihan;
    char lagi;

    CreateStack(&S);

    do {
        printf("\n===========\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print Stack\n");
        printf("4. Search Elemen\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("\n=== PUSH (999 untuk berhenti) ===\n");
                while (1) {
                    printf("Masukkan elemen: ");
                    scanf("%d", &x);

                    if (x == 999) {
                        break;
                    }

                    if (!IsStackFull(S)) {
                        Push(&S, x);
                    } else {
                        printf("Stack penuh!\n");
                        break;
                    }
                }
                break;

            case 2:
                printf("\n=== POP ===\n");
                do {
                    if (IsStackEmpty(S)) {
                        printf("Stack kosong!\n");
                        break;
                    }

                    Pop(&S, &x);
                    printf("Elemen di-pop: %d\n", x);

                    printf("Isi stack sekarang: ");
                    PrintStackInfo(S);
                    printf("\n");

                    printf("Lagi? (y/n): ");
                    scanf(" %c", &lagi);

                } while (lagi == 'y' || lagi == 'Y');
                break;

            case 3:
                printf("\nIsi stack: ");
                PrintStackInfo(S);
                printf("\n");
                break;

            case 4:
                printf("\n=== SEARCH ===\n");
                if (IsStackEmpty(S)) {
                    printf("Stack kosong!\n");
                    break;
                }

                printf("Masukkan elemen yang dicari: ");
                scanf("%d", &x);

                if (isInfoKetemu(S, x)) {
                    printf("Elemen ditemukan!\n");
                    printf("Index: %d\n", CariElemenStack(S, x));
                } else {
                    printf("Elemen tidak ditemukan!\n");
                }
                break;

            case 0:
                printf("Keluar...\n");
                break;

            default:
                printf("Pilihan tidak valid!\n");
        }

    } while (pilihan != 0);

    return 0;
}