#include <stdio.h>
#include "globalvar.h"
#include "nilai.h"
#include "mahasiswa.h"
#include "matakuliah.h"

char gradchar(float nilai){
    if (nilai >= 80) return 'A';
    else if (nilai >= 70) return 'B';
    else if (nilai >= 60) return 'C';
    else if (nilai >= 50) return 'D';
    else return 'E';
};

void tambahNilai(MatKul mk[], Nilai nl[], Mahasiswa1 mhs[] ,int jumlahMatkul, int *jumlahNilai, int jumlahMhs){
    int pilihMhs;
    int pilihMk;

    if (jumlahMatkul == 0){
        printf("Mata Kuliah Belum Ada\n");
        return;
    };

    if (jumlahMhs == 0){
        printf("Mahasiswa Belum Ada.\n");
        return;
    }

    if (*jumlahNilai >= MAX * MAX){
        printf("Data nilai penuh!\n");
        return;
    }

    tampilMahasiswa(mhs, jumlahMhs);
    printf("Pilih nomor Mahasiswa : "); scanf("%d", &pilihMhs);

    int idx = pilihMhs - 1;

    if (pilihMhs < 1 || pilihMhs > jumlahMhs){
        printf("Pilihan tidak valid!\n");
        return;

    }
    
    tampilMK(mk, jumlahMatkul);
    printf("\nPilih nomor Mata Kuliah : "); scanf("%d", &pilihMk);

    int idx2 = pilihMk - 1;

    if (pilihMk < 1 || pilihMk > jumlahMatkul){
        printf("Pilihan tidak valid!\n");
        return;
    }

    int p;

    for (p = 0; p < *jumlahNilai; p++){
        if (nl[p].IdNim == mhs[idx].nim){
            if(nl[p].IdMk == mk[idx2].IdMk){
                printf("\nNilai sudah ada!");
                return;
            }
        };
    };

    printf("Masukan Nilai : "); scanf("%2f", &nl[*jumlahNilai].nilai_angka);
    nl[*jumlahNilai].IdMk = mk[idx2].IdMk;
    nl[*jumlahNilai].IdNim = mhs[idx].nim;
    nl[*jumlahNilai].nilai_huruf = gradchar(nl[*jumlahNilai].nilai_angka);

    *jumlahNilai = *jumlahNilai + 1;
};

void tampilNilai(MatKul mk[], Nilai nl[], Mahasiswa1 mhs[],
    int jumlahMatkul, int jumlahNilai, int jumlahMhs){

    if (jumlahMatkul == 0){
        printf("Mata Kuliah Belum Ada\n");
        return;
    };

    if (jumlahMhs == 0){
        printf("Mahasiswa Belum Ada.\n");
        return;
    }

    if (jumlahNilai >= MAX * MAX){
        printf("Data nilai penuh!\n");
        return;
    }

    printf("No. Nim | Nama | Matkul | Nilai | Grade\n");
    for (int i = 0; i < jumlahNilai; i++){

        int idxMhs = -1;
        int idxMk = -1;

        // cari mahasiswa berdasarkan IdNim
        for (int j = 0; j < jumlahMhs; j++){
            if (nl[i].IdNim == mhs[j].nim){
                idxMhs = j;
                break;
            }
        }

        // cari matkul berdasarkan IdMk
        for (int k = 0; k < jumlahMatkul; k++){
            if (nl[i].IdMk == mk[k].IdMk){
                idxMk = k;
                break;
            }
        }

        if (idxMhs != -1 && idxMk != -1){
            printf("%d. %d | %s | %s | %.2f | %c\n",
                i + 1,
                mhs[idxMhs].nim,
                mhs[idxMhs].nama,
                mk[idxMk].nama_mk,
                nl[i].nilai_angka,
                nl[i].nilai_huruf
            );
        }
    }
}