#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "doubleLinkList.h"

int main() {
    List Q;
    CreateList(&Q);

    int pilihan = 0;
    infotype X, Y;
    char lagi;
    int sedangDilayani = -1;
    int jumlahAntrian = 0;

    do {
        system("clear");
        system("cls");
        printf("\nInformasi Antrian:\n");
        if (sedangDilayani == -1) {
            printf("Sedang Dilayani : Kosong\n");
        } else {
            printf("Sedang Dilayani : %d\n", sedangDilayani);
        }
        printf("Jumlah Antrian  : %d\n", jumlahAntrian);
        
        printf("\n==================\n");
        printf("1. Tambah Antrian Baru\n");
        printf("2. Layani Antrian\n");
        printf("3. Cetak Semua Antrian\n");
        printf("4. Sisip VIP di Depan\n");
        printf("5. Sisip Setelah Nomor\n");
        printf("6. Hapus Antrian Ujung\n");
        printf("0. Keluar\n");
        printf("Pilihan : ");
        scanf("%d", &pilihan);

        switch (pilihan) {

            case 1:
                printf("\n=== Tambah Antrian ===\n");
                while (1) {
                    printf("Masukkan Kode Nomor Antrian: ");
                    scanf("%d", &X);

                    AddLast(&Q, X);
                    jumlahAntrian++;

                    printf("Tambah Lagi? (y/n): ");
                    scanf(" %c", &lagi);

                    if (lagi == 'n' || lagi == 'N') {
                        break;
                    }
                }
                break;

            case 2:
                printf("\n=== Layani Antrian ===\n");
                printf("Isi Antrian saat ini : ");
                if (!ListEmpty(Q)) {
                    CetakAll(Q);
                    printf("\n");
                } else {
                    printf("Kosong\n");
                }

                if (ListEmpty(Q)) {
                    printf("\nAntrian Kosong!\n");
                    printf("Tekan enter untuk lanjut...");
                    getchar();
                    getchar();
                    break;
                }

                do {
                    printf("\nProses Layani? (y/n): ");
                    scanf(" %c", &lagi);

                    if (lagi == 'n' || lagi == 'N') {
                        break;
                    }

                    if (ListEmpty(Q)) {
                        printf("Antrian Kosong!\n");
                        printf("Tekan enter untuk lanjut...");
                        getchar();
                        getchar();
                        break;
                    }

                    DelFirst(&Q, &X);
                    sedangDilayani = X;
                    jumlahAntrian--;
                    
                    printf("Dilayani: %d | Sisa Antrian: %d\n", sedangDilayani, jumlahAntrian);

                    if (!ListEmpty(Q)) {
                        printf("\nIsi Antrian tersisa : ");
                        CetakAll(Q);
                        printf("\n");
                    } else {
                        printf("\n");
                    }

                } while (lagi == 'y' || lagi == 'Y');
                break;

            case 3:
                if (ListEmpty(Q)) {
                    printf("\nAntrian Kosong!\n");
                    printf("Tekan enter untuk lanjut...");
                    getchar();
                    getchar();
                    break;
                }

                printf("\nIsi Antrian saat ini: ");
                CetakAll(Q);
                printf("\n\nTekan enter untuk lanjut...");
                getchar();
                getchar();
                break;
                
            case 4:
                printf("\n=== Sisip Depan ===\n");
                printf("Masukkan Nomor Antrian : ");
                scanf("%d", &X);
                AddFirst(&Q, X);
                jumlahAntrian++;
                printf("Tekan enter untuk lanjut...");
                getchar();
                getchar();
                break;

            case 5:
                printf("\n=== Sisip Tengah ===\n");
                printf("Masukkan Nomor Antrian Baru: ");
                scanf("%d", &X);
                printf("Disisipkan setelah antrian nomor berapa?: ");
                scanf("%d", &Y);
                AddInElm(&Q, X, Y);
                jumlahAntrian++;
                printf("Tekan enter untuk lanjut...");
                getchar();
                getchar();
                break;
                
            case 6:
                printf("\n=== Hapus Ujung ===\n");
                if (ListEmpty(Q)) {
                    printf("\nAntrian Kosong!\n");
                } else {
                    DelLast(&Q, &X);
                    jumlahAntrian--;
                    printf("Antrian nomor %d dihapus.\n", X);
                }
                printf("Tekan enter untuk lanjut...");
                getchar();
                getchar();
                break;

            case 0:
                printf("Keluar program...\n");
                break;

            default:
                printf("Pilihan tidak valid!\n");
                getchar();
                getchar();
        }

    } while (pilihan != 0);

    return 0;
}