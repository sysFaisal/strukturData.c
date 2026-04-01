#include <stdio.h>
#include <string.h>
#include <windows.h>

#define MAX 20

typedef struct {
    int nim;
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

        mhs[*jumlahMhs].nim = *jumlahMhs + 1;
        sprintf(mhs[*jumlahMhs].nama, "Nama%d", *jumlahMhs + 1);
        sprintf(mhs[*jumlahMhs].jurusan, "Informatika%d", *jumlahMhs + 1);
        sprintf(mhs[*jumlahMhs].jenis_kelamin, (i % 2 == 0) ? "Laki-laki" : "Perempuan");
        sprintf(mhs[*jumlahMhs].kelas, "Kelas%d", *jumlahMhs + 1);
        /*
        printf("NIM: "); scanf("%d", &mhs[*jumlahMhs].nim);
        printf("Nama: "); scanf("%s", mhs[*jumlahMhs].nama);
        printf("Jurusan: "); scanf("%s", mhs[*jumlahMhs].jurusan);
        printf("Jenis Kelamin: "); scanf("%s", mhs[*jumlahMhs].jenis_kelamin);
        printf("Kelas: "); scanf("%s", mhs[*jumlahMhs].kelas);

        */
        (*jumlahMhs)++;
    }

    printf("%d Mahasiswa berhasil ditambahkan\n", n);
};

void tampilMahasiswa(Mahasiswa1 mhs[], int jumlahMhs){
    if (jumlahMhs == 0){
        printf("Tidak ada mahasiswa.\n");
        return;
    }

    printf("\n=== Data Mahasiswa ===\n");
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

    printf("NIM: "); scanf("%d", &mhs[idx].nim);
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

    (*jumlahMhs)--;

    printf("Data berhasil dihapus!\n");
}



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
    for ( i = 0; i < jumlahMatkul; i++){
        printf("%d. %d | %s | %s | %s | %d \n",
            i + 1,
            mk[i].IdMk,
            mk[i].kode_mk,
            mk[i].nama_mk,
            mk[i].pengajar,
            mk[i].sks
        );
    }
};

char gradchar(float nilai){
    if (nilai >= 80) return 'A';
    else if (nilai >= 70) return 'B';
    else if (nilai >= 60) return 'C';
    else if (nilai >= 50) return 'D';
    else return 'E';
}

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
    printf("Pilih nomor Mahasiswa: "); scanf("%d", &pilihMhs);

    int idx = pilihMhs - 1;

    if (pilihMhs < 1 || pilihMhs > jumlahMhs){
        printf("Pilihan tidak valid!\n");
        return;

    }
    
    tampilMK(mk, jumlahMatkul);
    printf("\nPilih nomor Mata Kuliah"); scanf("%d", &pilihMk);

    int idx2 = pilihMk - 1;

    if (pilihMk < 1 || pilihMk > jumlahMatkul){
        printf("Pilihan tidak valid!\n");
        return;
    }

    printf("Masukan Nilai : "); scanf("%2f", &nl[*jumlahNilai].nilai_angka);
    nl[*jumlahNilai].IdMk = mk[idx2].IdMk;
    nl[*jumlahNilai].IdNim = mhs[idx].nim;
    nl[*jumlahNilai].nilai_huruf = gradchar(nl[*jumlahNilai].nilai_angka);

    *jumlahNilai = *jumlahNilai + 1;
};

void tampilNilai(MatKul mk[], Nilai nl[], Mahasiswa1 mhs[],
                 int jumlahMatkul, int jumlahNilai, int jumlahMhs){

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


int main(){
    Mahasiswa1 mhs[MAX];
    MatKul mk[MAX];
    Nilai nl[MAX * MAX];

    int jumlahMhs = 0;
    int jumlahMatkul = 0;
    int jumlahNilai = 0;
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
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        switch(pilih){
            case 1: tambahMahasiswa(mhs, &jumlahMhs); break;
            case 2: tampilMahasiswa(mhs, jumlahMhs); break;
            case 3: editMahasiswa(mhs, jumlahMhs); break;
            case 4: hapusMahasiswa(mhs, &jumlahMhs); break;
            case 5: tambahMK(mk, &jumlahMatkul); break;
            case 6: tampilMK(mk, jumlahMatkul); break;
            case 7: tambahNilai(mk, nl, mhs, jumlahMatkul, &jumlahNilai, jumlahMhs); break;
            case 8: tampilNilai(mk, nl, mhs, jumlahMatkul, jumlahNilai, jumlahMhs); break;
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
