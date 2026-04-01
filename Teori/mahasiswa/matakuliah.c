#include <stdio.h>
#include "matakuliah.h"

MataKuliah mk[100];
int jumlahMk = 0;

void tambahMK() {
    printf("Kode MK: "); scanf("%s", mk[jumlahMk].kode_mk);
    printf("Nama MK: "); scanf(" %[^\n]", mk[jumlahMk].nama_mk);
    printf("SKS: "); scanf("%d", &mk[jumlahMk].sks);
    printf("Pengajar: "); scanf(" %[^\n]", mk[jumlahMk].pengajar);

    jumlahMk++;
}

void tampilMK() {
    for(int i = 0; i < jumlahMk; i++) {
        printf("\n%s | %s | %d | %s",
            mk[i].kode_mk,
            mk[i].nama_mk,
            mk[i].sks,
            mk[i].pengajar);
    }
}