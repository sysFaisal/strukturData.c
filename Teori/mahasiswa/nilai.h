#ifndef NILAI_H
#define NILAI_H

typedef struct {
    char nim[15];
    char kode_mk[10];
    float nilai_angka;
    char nilai_huruf;
} Nilai;

void tambahNilai();
void tampilNilai();

#endif