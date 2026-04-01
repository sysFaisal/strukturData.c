#ifndef _MAHASISWA_H
#define _MAHASISWA_H

typedef struct {
    int nim;
    char nama[50];
    char jurusan[50];
    char jenis_kelamin[20];
    char kelas[20];
} Mahasiswa1;

void tambahMahasiswa(Mahasiswa1 mhs[], int *jumlahMhs);
void tampilMahasiswa(Mahasiswa1 mhs[], int jumlahMhs);
void editMahasiswa(Mahasiswa1 mhs[], int jumlahMhs);
void hapusMahasiswa(Mahasiswa1 mhs[], int *jumlahMhs);

#endif 