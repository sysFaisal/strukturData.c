#include <stdio.h>
#include <string.h>
#include "mahasiswa.h"
#include "matakuliah.h"
#include "nilai.h"
#include "globalvar.h"

int main(){
    Mahasiswa1 mhs[MAX];
    MatKul mk[MAX];
    Nilai nl[MAX * MAX];

    int counterMhs = 0;
    int counterMatkul = 0;
    int counterNilai = 0;
    int pilih;

    do {
        printf("\n=== SISTEM AKADEMIK ===\n");
        printf("1. Tambah Mahasiswa\n");
        printf("2. Tampil Mahasiswa\n");
        printf("3. Edit Mahasiswa\n");
        printf("4. Hapus Mahasiswa\n");
        printf("5. Tambah MataKuliah\n");
        printf("6. Tampil Matakuliah\n");
        printf("7. Tambah Nilai\n");
        printf("8. Tampil Nilai\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        switch(pilih){
            case 1: tambahMahasiswa(mhs, &counterMhs); break;
            case 2: tampilMahasiswa(mhs, counterMhs); break;
            case 3: editMahasiswa(mhs, counterMhs); break;
            case 4: hapusMahasiswa(mhs, &counterMhs , nl, &counterNilai); break;
            case 5: tambahMK(mk, &counterMatkul); break;
            case 6: tampilMK(mk, counterMatkul); break;
            case 7: tambahNilai(mk, nl, mhs, counterMatkul, &counterNilai, counterMhs); break;
            case 8: tampilNilai(mk, nl, mhs, counterMatkul, counterNilai, counterMhs); break;
            case 0: printf("Keluar...\n"); break;
            default: printf("Pilihan tidak tersedia!\n");
        }

    } while (pilih != 0);

    return 0;
}
