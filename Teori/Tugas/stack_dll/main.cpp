#include <iostream>
#include "func.h"
#include <cstdlib>

int main (){
    Stack *Q = initStack();
    int pilihan = 0, x = 0;
    char lagi;
    string namaBuku;

    do {
        system("clear");
        cout << endl <<"==================" << endl;
        cout << "1. Tumpuk Buku (Push)"<< endl;
        cout << "2. Ambil Buku (Pop)" << endl;
        cout << "3. Cetak Semua Buku" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;

        switch (pilihan) {

            case 1:
                cout << endl << "=== Push ===" << endl;
                while (1) {
                    cout << "Masukan Nama Buku : ";
                    cin >> namaBuku;

                    push(Q, namaBuku);

                    cout << "Lagi? (y/n): ";
                    cin >> lagi;

                    if (lagi == 'n' || lagi == 'N') {
                        break;
                    }
                }
                break;

            case 2:

                cout << endl << "=== Pop ===" << endl;
                cout << "Isi Buku dalam stack : ";
                cetakStack(Q);
                cout << endl;

                if (isEmptyStack(Q)) {
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

                    pop(Q, &namaBuku);
                    cout << "Buku yg dikeluar: " << namaBuku << endl;

                    if (isEmptyStack(Q)) {
                        cout << endl << "Stack Kosong!" << endl;
                        cout << "Tekan enter untuk lanjut...";
                        cin.ignore();
                        cin.get();
                        break;
                    }

                    cout << "Isi Buku dalam Stack : ";
                    cetakStack(Q);
                    cout << endl;



                } while (lagi == 'y' || lagi == 'Y');

                break;

            case 3:

                if (isEmptyStack(Q)) {
                    cout << endl << "Stack Kosong!" << endl;
                    cout << "Tekan enter untuk lanjut...";
                    cin.ignore();
                    cin.get();
                    break;
                }

                cout << endl <<"Isi Buku dalam stack: ";
                cetakStack(Q);
                cout << endl;

                cout << "Tekan enter untuk lanjut...";
                cin.ignore();
                cin.get();
                break;

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
