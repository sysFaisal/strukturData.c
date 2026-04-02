#ifndef _NILAI_H
#define _NILAI_H

#include "globalvar.h"
#include "mahasiswa.h"
#include "matakuliah.h"

char gradchar(float nilai);
void tambahNilai(MatKul mk[], Nilai nl[], Mahasiswa1 mhs[] ,int jumlahMatkul, int *jumlahNilai, int jumlahMhs);
void tampilNilai(MatKul mk[], Nilai nl[], Mahasiswa1 mhs[], int jumlahMatkul, int jumlahNilai, int jumlahMhs);
void hapusNilai_Nim(Nilai nl[], int *jumlahNilai, int targetNim);

#endif