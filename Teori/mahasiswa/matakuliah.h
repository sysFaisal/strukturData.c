#ifndef MATAKULIAH_H
#define MATAKULIAH_H

typedef struct {
    char kode_mk[10];
    char nama_mk[50];
    int sks;
    char pengajar[50];
} MataKuliah;

void tambahMK();
void tampilMK();

#endif