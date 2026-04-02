#include <stdio.h>
#include <string.h>
#include "globalvar.h"
#include "mahasiswa.h"


void tambahMK(MatKul mk[], int *jumlahMatkul){
    char fix;

    do {
        if (*jumlahMatkul >= MAX){
            printf("Data penuh!\n");
            return;
        }

        printf("\n=== Data MataKuliah ===\n");
        printf("Masukan Kode Matakuliah : "); scanf("%s", mk[*jumlahMatkul].kode_mk);
        printf("Masukan Nama Matakuliah : "); scanf("%s", mk[*jumlahMatkul].nama_mk);
        printf("Masukan Sks Matakuliah : "); scanf("%d", &mk[*jumlahMatkul].sks);
        printf("Masukan Pengajar Matakuliah : "); scanf("%s", mk[*jumlahMatkul].pengajar);
        mk[*jumlahMatkul].IdMk = *jumlahMatkul + 1; 

        *jumlahMatkul = *jumlahMatkul + 1;

        printf("Lanjutkan ? y/n : "); scanf(" %c", &fix); 
    } while (fix == 'y');

};

void tampilMK(MatKul mk[], int jumlahMatkul){

    if (jumlahMatkul == 0){
        printf("Tidak ada matakuliah.\n");
        return;
    }

    int i;

    printf("\n=== Data MataKuliah ===\n");
    printf("No. idMk | Kode_Mk | Nama_Mk | Dosen | Sks\n");
    for ( i = 0; i < jumlahMatkul; i++){
        printf("%d. %d | %s | %s | %s | %d \n",
            i + 1,
            mk[i].IdMk,
            mk[i].kode_mk,
            mk[i].nama_mk,
            mk[i].pengajar,
            mk[i].sks
        );
    };
    
};

void hapusMK(MatKul mk[], int *jumlahMatkul, Nilai nl[], int *jumlahNilai){

    if (*jumlahMatkul == 0){
        printf("Belum Ada Mata Kuliah!");
        return;
    };

    int temp = *jumlahMatkul;
    tampilMK(mk, temp);

    int pilih;
    printf("Masukan Mata Kuliah Yang Ingin Dihapus : "); scanf("%d", &pilih);

    int idx = pilih - 1;

    if (pilih < 1 || pilih > *jumlahMatkul){
        printf("Pilihan tidak valid!\n");
        return;
    };

    if (*jumlahNilai != 0){
        hapusNilai_Mk(nl , jumlahNilai , mk[idx].IdMk);
    };

    for (int i = idx; i < *jumlahMatkul - 1; i++){
        mk[i] = mk[i + 1];
    };

    *jumlahMatkul = *jumlahMatkul - 1;

    printf("Data Mata Kuliah berhasil dihapus!\n");
};