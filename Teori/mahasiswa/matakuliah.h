#ifndef _MATAKULIAH_H
#define _MATAKULIAH_H

typedef struct {
    int IdMk;
    char kode_mk[10];
    char nama_mk[50];
    int sks;
    char pengajar[50];
} MatKul;

void tambahMK(MatKul mk[], int *jumlahMatkul);
void tampilMK(MatKul mk[], int jumlahMatkul);

#endif 