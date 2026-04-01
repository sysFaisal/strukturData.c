#include <stdio.h>
#include <string.h>
#include "mahasiswa.h"

Mahasiswa mhs[MAX];
int jumlahMhs = 0;

void tambahMahasiswa() {
    printf("NIM: "); scanf("%s", mhs[jumlahMhs].nim);
    printf("Nama: "); scanf(" %[^\n]", mhs[jumlahMhs].nama);
    printf("Jurusan: "); scanf(" %[^\n]", mhs[jumlahMhs].jurusan);
    printf("Jenis Kelamin: "); scanf("%s", mhs[jumlahMhs].jenis_kelamin);
    printf("Kelas: "); scanf("%s", mhs[jumlahMhs].kelas);

    jumlahMhs++;
}

void tampilMahasiswa() {
    for(int i = 0; i < jumlahMhs; i++) {
        printf("\n%s | %s | %s | %s | %s",
            mhs[i].nim,
            mhs[i].nama,
            mhs[i].jurusan,
            mhs[i].jenis_kelamin,
            mhs[i].kelas);
    }
}

void editMahasiswa() {
    char nim[15];
    printf("NIM yang diedit: ");
    scanf("%s", nim);

    for(int i = 0; i < jumlahMhs; i++) {
        if(strcmp(nim, mhs[i].nim) == 0) {
            printf("Nama baru: "); scanf(" %[^\n]", mhs[i].nama);
            printf("Jurusan baru: "); scanf(" %[^\n]", mhs[i].jurusan);
            printf("JK baru: "); scanf("%s", mhs[i].jenis_kelamin);
            printf("Kelas baru: "); scanf("%s", mhs[i].kelas);
        }
    }
}

void hapusMahasiswa() {
    char nim[15];
    printf("NIM yang dihapus: ");
    scanf("%s", nim);

    for(int i = 0; i < jumlahMhs; i++) {
        if(strcmp(nim, mhs[i].nim) == 0) {
            for(int j = i; j < jumlahMhs - 1; j++) {
                mhs[j] = mhs[j + 1];
            }
            jumlahMhs--;
            break;
        }
    }
}