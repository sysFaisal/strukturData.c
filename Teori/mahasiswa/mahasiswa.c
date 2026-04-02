#include <stdio.h>
#include <string.h>
#include "globalvar.h"
#include "mahasiswa.h"
#include "nilai.h"

void tambahMahasiswa(Mahasiswa1 mhs[], int *jumlahMhs){
    int i, nimtemp;
    
    printf("NIM: "); scanf("%d", &nimtemp);

    for (i = 0; i < *jumlahMhs; i++){
        if (mhs[i].nim == nimtemp){
            printf("Nim Tidak Boleh Sama\n");
            return;
        };
    };
    mhs[*jumlahMhs].nim = nimtemp;

    printf("Nama: "); scanf("%s", mhs[*jumlahMhs].nama);
    printf("Jurusan: "); scanf("%s", mhs[*jumlahMhs].jurusan);
    printf("Jenis Kelamin: "); scanf("%s", mhs[*jumlahMhs].jenis_kelamin);
    printf("Kelas: "); scanf("%s", mhs[*jumlahMhs].kelas);
    (*jumlahMhs)++;

    printf("Mahasiswa berhasil ditambahkan\n");
};

void tampilMahasiswa(Mahasiswa1 mhs[], int jumlahMhs){
    if (jumlahMhs == 0){
        printf("Tidak ada mahasiswa.\n");
        return;
    }

    printf("\n=== Data Mahasiswa ===\n");
    printf("No | Nim | Nama | Jurusan | Gender | Kelas\n");
    for (int i = 0; i < jumlahMhs; i++){
        printf("%d. %d | %s | %s | %s | %s\n",
            i + 1,
            mhs[i].nim,
            mhs[i].nama,
            mhs[i].jurusan,
            mhs[i].jenis_kelamin,
            mhs[i].kelas
        );
    }

};

void editMahasiswa(Mahasiswa1 mhs[], int jumlahMhs){
    int pilih;

    if (jumlahMhs == 0){
        printf("Tidak ada mahasiswa.\n");
        return;
    }

    tampilMahasiswa(mhs, jumlahMhs);

    printf("Pilih nomor mahasiswa: ");
    scanf("%d", &pilih);

    if (pilih < 1 || pilih > jumlahMhs){
        printf("Pilihan tidak valid!\n");
        return;
    }

    int idx = pilih - 1;

    printf("\n=== Edit Mahasiswa ===\n");

    printf("Nama: "); scanf("%s", mhs[idx].nama);
    printf("Jurusan: "); scanf("%s", mhs[idx].jurusan);
    printf("Jenis Kelamin: "); scanf("%s", mhs[idx].jenis_kelamin);
    printf("Kelas: "); scanf("%s", mhs[idx].kelas);

    printf("Data berhasil diubah!\n");
};

void hapusMahasiswa(Mahasiswa1 mhs[], int *jumlahMhs , Nilai nl[], int *jumlahNilai){
    int pilih;

    if (*jumlahMhs == 0){
        printf("Tidak ada mahasiswa.\n");
        return;
    }

    tampilMahasiswa(mhs, *jumlahMhs);

    printf("Pilih nomor mahasiswa yang ingin dihapus: "); scanf("%d", &pilih);

    if (pilih < 1 || pilih > *jumlahMhs){
        printf("Pilihan tidak valid!\n");
        return;
    }

    int idx = pilih - 1;

    if (*jumlahNilai != 0){
        hapusNilai_Nim(nl , jumlahNilai , mhs[idx].nim);
    };

    for (int i = idx; i < *jumlahMhs - 1; i++){
        mhs[i] = mhs[i + 1];
    };
    
    *jumlahMhs = *jumlahMhs - 1;

    printf("Data Mahasiswa berhasil dihapus!\n");
};