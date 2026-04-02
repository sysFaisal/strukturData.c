#ifndef _GLOBALVAR_H
#define _GLOBALVAR_H

#define MAX 20

typedef struct {
    int nim;
    char nama[50];
    char jurusan[50];
    char jenis_kelamin[20];
    char kelas[20];
} Mahasiswa1;

typedef struct {
    int IdMk;
    char kode_mk[10];
    char nama_mk[50];
    int sks;
    char pengajar[50];
} MatKul;

typedef struct {
    int IdNim;
    int IdMk;
    float nilai_angka;
    char nilai_huruf;
} Nilai;

#endif 