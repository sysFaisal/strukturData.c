#ifndef _MAHASISWA_H
#define _MAHASISWA_H
#include "globalvar.h"
#include "nilai.h"

void tambahMahasiswa(Mahasiswa1 mhs[], int *jumlahMhs);
void tampilMahasiswa(Mahasiswa1 mhs[], int jumlahMhs);
void editMahasiswa(Mahasiswa1 mhs[], int jumlahMhs);
void hapusMahasiswa(Mahasiswa1 mhs[], int *jumlahMhs, Nilai nl[], int *jumlahNilai);

#endif 