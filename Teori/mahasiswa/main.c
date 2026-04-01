#include <stdio.h>
#include <string.h>

#define MAX 20

typedef struct {
    char nim[20];
    char nama[50];
    char jurusan[50];
    char jenis_kelamin[20];
    char kelas[20];
} Mahasiswa1;

void tambahMahasiswa(Mahasiswa1 mhs[], int *jumlahMhs){
    int n = 3; 

    for (int i = 0; i < n; i++){
        if (*jumlahMhs >= MAX){
            printf("Data penuh!\n");
            return;
        }

        sprintf(mhs[*jumlahMhs].nim, "NIM%d", *jumlahMhs + 1);
        sprintf(mhs[*jumlahMhs].nama, "Nama%d", *jumlahMhs + 1);
        sprintf(mhs[*jumlahMhs].jurusan, "Informatika%d", *jumlahMhs + 1);
        sprintf(mhs[*jumlahMhs].jenis_kelamin, (i % 2 == 0) ? "Laki-laki" : "Perempuan");
        sprintf(mhs[*jumlahMhs].kelas, "Kelas%d", *jumlahMhs + 1);
        /*
        printf("NIM: "); scanf("%s", mhs[*jumlahMhs].nim);
        printf("Nama: "); scanf("%s", mhs[*jumlahMhs].nama);
        printf("Jurusan: "); scanf("%s", mhs[*jumlahMhs].jurusan);
        printf("Jenis Kelamin: "); scanf("%s", mhs[*jumlahMhs].jenis_kelamin);
        printf("Kelas: "); scanf("%s", mhs[*jumlahMhs].kelas);

        */
        (*jumlahMhs)++;
    }

    printf("%d Mahasiswa berhasil ditambahkan\n", n);
}

void tampilMahasiswa(Mahasiswa1 mhs[], int jumlahMhs){
    if (jumlahMhs == 0){
        printf("Tidak ada mahasiswa.\n");
        return;
    }

    printf("\n=== Data Mahasiswa ===\n");
    for (int i = 0; i < jumlahMhs; i++){
        printf("%d. %s | %s | %s | %s | %s\n",
            i + 1,
            mhs[i].nim,
            mhs[i].nama,
            mhs[i].jurusan,
            mhs[i].jenis_kelamin,
            mhs[i].kelas
        );
    }
}

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

    printf("NIM: "); scanf("%s", mhs[idx].nim);
    printf("Nama: "); scanf("%s", mhs[idx].nama);
    printf("Jurusan: "); scanf("%s", mhs[idx].jurusan);
    printf("Jenis Kelamin: "); scanf("%s", mhs[idx].jenis_kelamin);
    printf("Kelas: "); scanf("%s", mhs[idx].kelas);

    printf("Data berhasil diubah!\n");
}

void hapusMahasiswa(Mahasiswa1 mhs[], int *jumlahMhs){
    int pilih;

    if (*jumlahMhs == 0){
        printf("Tidak ada mahasiswa.\n");
        return;
    }

    tampilMahasiswa(mhs, *jumlahMhs);

    printf("Pilih nomor mahasiswa yang ingin dihapus: ");
    scanf("%d", &pilih);

    if (pilih < 1 || pilih > *jumlahMhs){
        printf("Pilihan tidak valid!\n");
        return;
    }

    int idx = pilih - 1;

    for (int i = idx; i < *jumlahMhs - 1; i++){
        mhs[i] = mhs[i + 1];
    }

    strcpy(mhs[*jumlahMhs - 1].jenis_kelamin , "");
    strcpy(mhs[*jumlahMhs - 1].jurusan , "");
    strcpy(mhs[*jumlahMhs - 1].kelas , "");
    strcpy(mhs[*jumlahMhs - 1].nama , "");
    strcpy(mhs[*jumlahMhs - 1].nim , "");

    (*jumlahMhs)--;

    printf("Data berhasil dihapus!\n");
}

int main(){
    Mahasiswa1 mhs[MAX];
    int jumlahMhs = 0;
    int pilih;

    do {
        printf("\n=== SISTEM AKADEMIK ===\n");
        printf("1. Tambah Mahasiswa\n");
        printf("2. Tampil Mahasiswa\n");
        printf("3. Edit Mahasiswa\n");
        printf("4. Hapus Mahasiswa\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        
        switch(pilih){
            case 1: tambahMahasiswa(mhs, &jumlahMhs); break;
            case 2: tampilMahasiswa(mhs, jumlahMhs); break;
            case 3: editMahasiswa(mhs, jumlahMhs); break;
            case 4: hapusMahasiswa(mhs, &jumlahMhs); break;
            case 0: printf("Keluar...\n"); break;
            default: printf("Pilihan tidak tersedia!\n");
        }

    } while (pilih != 0);

    return 0;
}
/*
            case 5: tambahMK(); break;
            case 6: tampilMK(); break;
            case 7: tambahNilai(); break;
            case 8: tampilNilai(); break;
*/
