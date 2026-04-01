#include <stdio.h>
#include "mahasiswa.h"
#include "matakuliah.h"
#include "nilai.h"

int main() {
    int pilih;

    do {
        printf("\n=== SISTEM AKADEMIK ===");
        printf("\n1. Tambah Mahasiswa");
        printf("\n2. Tampil Mahasiswa");
        printf("\n3. Edit Mahasiswa");
        printf("\n4. Hapus Mahasiswa");
        printf("\n5. Tambah Mata Kuliah");
        printf("\n6. Tampil Mata Kuliah");
        printf("\n7. Tambah Nilai");
        printf("\n8. Tampil Nilai");
        printf("\n0. Keluar");
        printf("\nPilih: ");
        scanf("%d", &pilih);

        switch(pilih) {
            case 1: tambahMahasiswa(); break;
            case 2: tampilMahasiswa(); break;
            case 3: editMahasiswa(); break;
            case 4: hapusMahasiswa(); break;
            case 5: tambahMK(); break;
            case 6: tampilMK(); break;
            case 7: tambahNilai(); break;
            case 8: tampilNilai(); break;
        }

    } while(pilih != 0);

    return 0;
}