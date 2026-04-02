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
    printf("Pilih nomor Mata Kuliah : "); scanf("%d", &pilihMk);

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

void tampilNilai(MatKul mk[], Nilai nl[], Mahasiswa1 mhs[], int jumlahMatkul, int jumlahNilai, int jumlahMhs){

    if (jumlahMatkul == 0){
        printf("Mata Kuliah Belum Ada\n");
        return;
    };

    if (jumlahMhs == 0){
        printf("Mahasiswa Belum Ada.\n");
        return;
    }

    if (jumlahNilai == 0){
        printf("Belum Mengisi Nilai");
        return;
    };

    if (jumlahNilai >= MAX * MAX){
        printf("Data nilai penuh!\n");
        return;
    }

    int flag, flag1, p, j, o;
    int count = 0;

    printf("\nNo. Nim | Nama | Matkul | Nilai | Grade | Sks | Pengajar\n");
    for (p = 0; p < jumlahMhs; p++){

        for (j = 0; j < jumlahNilai; j++){
            flag = -1; 
            flag1 = -1;

            if (nl[j].IdNim == mhs[p].nim){
                flag = p;

                for (o = 0; o < jumlahMatkul; o++){
                    if (nl[j].IdMk == mk[o].IdMk){
                        flag1 = o;
                        break;
                    };
                };

                if (flag != -1 && flag1 != -1){
                    printf("%d. %d | %s | %s | %.2f | %c | %d | %s\n",
                    count + 1,
                    mhs[flag].nim,
                    mhs[flag].nama,
                    mk[flag1].nama_mk,
                    nl[j].nilai_angka,
                    nl[j].nilai_huruf,
                    mk[flag1].sks, 
                    mk[flag1].pengajar 
                    );
                }; 
            };
        };
    };
}

void geserNilai(Nilai nl[], int jumlahNilai , int idx){
    int i;

    for (i = idx; i < jumlahNilai - 1; i++){
        nl[i] = nl[i + 1];
    };

};

void hapusNilai_Nim(Nilai nl[], int *jumlahNilai, int targetNim){
    int i = 0;

    while (i < *jumlahNilai){
        if (nl[i].IdNim == targetNim){
            geserNilai(nl, *jumlahNilai, i);
            *jumlahNilai = *jumlahNilai - 1;
            
        } else {
            i++;
        }
    }

};