/* Program : main.c
Author : 2550081098, Faisal Fajari
Kelas : E
Deskripsi: Main driver dari prototype Tab Integer
Tanggal : 07/04/2026
*/
#include <stdio.h>
#include "boolean.h"
#include "tabint.h"

int main() {
    TabInt T1, T2, T3;
    int n, i, xCari, idxUbah, valUbah;
    
    CreateTabInt(&T1);

    printf("Berapa banyak elemen yang ingin dimasukkan ke T1? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        BacaElmt(&T1);
    }

    printf("\nIsi Tabel T1 saat ini:\n");
    CetakTabInt(T1);
    printf("\n");

    printf("Informasi Tabel T1:\n");
    printf("- Jumlah elemen  : %d\n", GetJumElmt(T1));
    printf("- Elemen pertama : %d\n", GetFirstIdx(T1));
    printf("- Elemen terakhir: %d\n\n", GetLastIdx(T1));

    if (!IsEmpty(T1)) {
        printf("Masukkan indeks elemen yang ingin diubah (1 - %d): ", GetJumElmt(T1));
        scanf("%d", &idxUbah);
        printf("Masukkan nilai baru: ");
        scanf("%d", &valUbah);

        printf("\n");

        SetEl(&T1, idxUbah, valUbah);
        printf("Isi Tabel T1 setelah diubah:\n");
        CetakTabInt(T1);
        printf("\n");
    }

    CreateTabInt(&T2);
    CopyTab(T1, &T2);
    printf("T1 disalin ke T2. Isi T2:\n");
    CetakTabInt(T2);
    if (IsEQTab(T1, T2)) {
        printf("Status: T1 dan T2 memiliki isi yang sama.\n\n");
    }

    T3 = KaliKons(T1, 2);
    printf("Hasil T1 dikalikan konstanta 2:\n");
    CetakTabInt(T3);
    printf("\n");

    T3 = KaliTab(T1, T2);
    printf("Hasil T1 dikalikan dengan T2:\n");
    CetakTabInt(T3);
    printf("\n");

    T3 = InverseTab(T1);
    printf("Hasil Inverse (kebalikan) dari T1:\n");
    CetakTabInt(T3);
    printf("\n");

    printf("Masukkan angka yang ingin dicari di dalam T1: ");
    scanf("%d", &xCari);

    if (isElemenAda(T1, xCari)) {
        printf("Angka %d ditemukan pada indeks ke-%d.\n", xCari, cariElemen(T1, xCari));
    } else {
        printf("Angka %d tidak ditemukan di dalam tabel.\n", xCari);
    }

    getchar();
    getchar();
    return 0;
}