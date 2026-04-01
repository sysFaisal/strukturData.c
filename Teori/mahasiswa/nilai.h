#ifndef _NILAI_H
#define _NILAI_H

#include "mahasiswa.h"
#include "matakuliah.h"


typedef struct {
    int IdNim;
    int IdMk;
    float nilai_angka;
    char nilai_huruf;
} Nilai;

char gradchar(float nilai);
void tambahNilai(MatKul mk[], Nilai nl[], Mahasiswa1 mhs[] ,int jumlahMatkul, int *jumlahNilai, int jumlahMhs);
void tampilNilai(MatKul mk[], Nilai nl[], Mahasiswa1 mhs[], int jumlahMatkul, int jumlahNilai, int jumlahMhs);

#endif