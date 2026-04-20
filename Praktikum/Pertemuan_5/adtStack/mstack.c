/* Program : mstack.c
Author : 2550081098, Faisal Fajari
Kelas : E
Deskripsi: Main Driver file dari prototype stack
Tanggal : 20/4/2026
*/
#include <stdio.h>
#include "boolean.h"
#include "stack.h"

int main() {
    Stack S;
    infotype x;
    int N, i;
    int jumlahPop = 0;

    CreateStack(&S);

    printf("Masukkan N: ");
    scanf("%d", &N);

    // Validasi
    if (N <= 0) {
        printf("Masukan tidak valid\n");
        return 0;
    }

    // Push bilangan ganjil
    for (i = 1; i <= N; i++) {
        if (i % 2 != 0) {
            Push(&S, i);
        }
    }

    // Pop dan tampilkan
    printf("\nHasil Pop:\n");
    while (!IsStackEmpty(S)) {
        Pop(&S, &x);
        printf("%d\n", x);
        jumlahPop++;
    }

    // Setelah kosong
    printf("Empty stack\n");
    printf("Jumlah elemen yang di-pop: %d\n", jumlahPop);


    getchar();
    getchar();

    return 0;
}