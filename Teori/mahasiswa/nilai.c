#include <stdio.h>

typedef struct {
    char nim[15];
    char kode_mk[10];
    float nilai_angka;
    char nilai_huruf;
} Nilai;

Nilai nilai[100];
int jumlahNilai = 0;

void tambahNilai() {
    printf("NIM: "); scanf("%s", nilai[jumlahNilai].nim);
    printf("Kode MK: "); scanf("%s", nilai[jumlahNilai].kode_mk);
    printf("Nilai Angka: "); scanf("%f", &nilai[jumlahNilai].nilai_angka);
    printf("Nilai Huruf: "); scanf(" %c", &nilai[jumlahNilai].nilai_huruf);

    jumlahNilai++;
}

void tampilNilai() {
    for(int i = 0; i < jumlahNilai; i++) {
        printf("\n%s | %s | %.2f | %c",
            nilai[i].nim,
            nilai[i].kode_mk,
            nilai[i].nilai_angka,
            nilai[i].nilai_huruf);
    }
}