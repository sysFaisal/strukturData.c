#include <iostream>
#include "func.h"
#include <cstdlib>

int main (){
    Stack Q = initStack();
    int pilihan = -1;
    char lagi;
    string namaBuku;

    do {
        system("clear");
        cout << endl <<"==================" << endl;
        cout << "1. Tumpuk Buku (Push)" << endl;
        cout << "2. Ambil Buku (Pop)" << endl;
        cout << "3. Cetak Semua Buku" << endl;
        cout << "4. Hitung Semua Buku" << endl;
        cout << "5. Lihat Buku (Peek Stack)" << endl;
        cout << "6. Ganti Buku (Change Stack)" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;

        switch (pilihan) {

            case 1:
                cout << endl << "=== Push ===" << endl;
                while (1) {
                    cout << "Masukan Nama Buku : ";
                    cin >> namaBuku;

                    push(&Q, namaBuku);

                    if (isFullStack(&Q)){
                        cout << "Stack Penuh!" << endl;
                        cout << "Tekan enter untuk keluar...";
                        cin.ignore();
                        cin.get();
                        break;
                    };

                    cout << "Lagi? (y/n): ";
                    cin >> lagi;

                    if (lagi == 'n' || lagi == 'N') {
                        break;
                    }
                }
                break;

            case 2:

                cout << endl << "=== Pop ===" << endl;
                cout << "Isi Buku dalam Stack : ";
                cetakStack(&Q);
                cout << endl;

                if (isEmptyStack(&Q)) {
                    cout << "Stack Kosong!" << endl;
                    cout << "Tekan enter untuk lanjut...";
                    cin.ignore();
                    cin.get();
                    break;
                }

                do {
                    cout << "Lagi? (y/n): ";
                    cin >> lagi;

                    if (lagi == 'n' || lagi == 'N') {
                        break;
                    }

                    pop(&Q, &namaBuku);
                    cout << "Buku yg dikeluar: " << namaBuku << endl;

                    if (isEmptyStack(&Q)) {
                        cout << endl << "Stack Kosong!" << endl;
                        cout << "Tekan enter untuk lanjut...";
                        cin.ignore();
                        cin.get();
                        break;
                    }

                    cout << "Isi Buku dalam Stack : ";
                    cetakStack(&Q);
                    cout << endl;

                } while (lagi == 'y' || lagi == 'Y');

                break;

            case 3:

                if (isEmptyStack(&Q)) {
                    cout << "Stack Kosong!" << endl;
                    cout << "Tekan enter untuk lanjut...";
                    cin.ignore();
                    cin.get();
                    break;
                }

                cout << endl <<"Isi Buku dalam stack: ";
                cetakStack(&Q);

                cout << "Tekan enter untuk lanjut...";
                cin.ignore();
                cin.get();
                break;

            case 4:

                if (isEmptyStack(&Q)) {
                    cout << "Stack Kosong!" << endl;
                    cout << "Tekan enter untuk lanjut...";
                    cin.ignore();
                    cin.get();
                    break;
                }

                cout << "Jumlah Buku: " << CountStack(&Q) << endl;

                cout << "Tekan enter untuk lanjut...";
                cin.ignore();
                cin.get();

                break;


            case 5:

                if (isEmptyStack(&Q)) {
                    cout << "Stack Kosong!" << endl;
                    cout << "Tekan enter untuk lanjut...";
                    cin.ignore();
                    cin.get();
                    break;
                }

                int posisiPeek;

                cout << "=== Peek Stack ===" << endl;
                cout << "Masukan Posisi: ";
                cin >> posisiPeek;

                peekStack(&Q, posisiPeek);

                cout << "Tekan enter untuk lanjut...";
                cin.ignore();
                cin.get();
                break;

            case 6: {

                if (isEmptyStack(&Q)) {
                    cout << "Stack Kosong!" << endl;
                    cout << "Tekan enter untuk lanjut...";
                    cin.ignore();
                    cin.get();
                    break;
                }

                int posisiChange;
                string bukuBaru;

                cout << "=== Change Stack ===" << endl;

                cout << "Masukan Posisi dari atas: ";
                cin >> posisiChange;

                cout << "Masukan Buku Baru: ";
                cin >> bukuBaru;

                changeStack(&Q, posisiChange, bukuBaru);

                cout << "Tekan enter untuk lanjut...";
                cin.ignore();
                cin.get();
                break;
            }
            case 0:
                cout << "Keluar program..." << endl ;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
                cin.ignore();
                cin.get();
        }

    } while (pilihan != 0);

    return 0;
};
