#ifndef MAHASISWA_H
#define MAHASISWA_H

#define MAX 100

typedef struct {
    char nim[15];
    char nama[50];
    char jurusan[50];
    char jenis_kelamin[10];
    char kelas[10];
} Mahasiswa;

void tambahMahasiswa();
void tampilMahasiswa();
void editMahasiswa();
void hapusMahasiswa();

#endif