#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "stack2.h"

int main() {
    Stack S;
    infotype x;
    int pilihan;
    char lagi;

    CreateStack(&S);

    do {
        printf("==================\n");
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

                    Push(&S, x);
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
                    printf("Elemen di pop: %d\n", x);

                    printf("Isi stack: ");
                    CetakStack(S);
                    printf("\n");

                    printf("Lagi? (y/n): ");
                    scanf(" %c", &lagi);

                } while (lagi == 'y' || lagi == 'Y');
                break;

            case 3:
                printf("\nIsi stack:\n");
                CetakStack(S);
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

                if (CariElemenStack(S, x)) {
                    printf("Elemen ditemukan!\n");
                } else {
                    printf("Elemen tidak ditemukan!\n");
                }
                break;

            case 0:
                printf("Keluar program...\n");
                break;

            default:
                printf("Pilihan tidak valid!\n");
        }

    } while (pilihan != 0);

    getchar();
    getchar();
    
    return 0;

}