#include <iostream>
#include "func.h"
#include <cstdlib>

int main (){
    Stack *Q = initStack();
    int pilihan = 0, x = 0;
    char lagi;
    
    do {
        system("clear");
        cout << endl <<"==================" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Cetak Stack" << endl;
        cout << "0. Keluar" << endl;
        cin >> pilihan;

        switch (pilihan) {

            case 1:
                cout << "=== Push (999 untuk berhenti) ===" << endl;
                while (1) {
                    cout << "Masukan Element: ";
                    cin >> x;

                    if (x == 999) {
                        break;
                    }

                    push(Q, x);
                }
                break;

            case 2:

                cout << endl << "=== Pop ===" << endl;
                cout << "Isi Stack : ";
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
                    pop(Q, &x);
                    cout << "Elemen yg dihapus:" << x << endl;

                    cout << "Isi Stack : ";
                    cetakStack(Q);
                    cout << endl;

                    if (isEmptyStack(Q)) {
                        cout << "Stack Kosong!" << endl;
                        cout << "Tekan enter untuk lanjut...";
                        cin.ignore();
                        cin.get();
                        break;
                    }

                    cout << "Lagi? (y/n): ";
                    cin >> lagi;

                    if (lagi == 'n' || lagi == 'N') {
                        break;
                    }

                } while (lagi == 'y' || lagi == 'Y');

                break;

            case 3:

                if (isEmptyStack(Q)) {
                    cout << "Stack Kosong!" << endl;
                    cout << "Tekan enter untuk lanjut...";
                    cin.ignore();
                    cin.get();
                    break;
                }

                cout << endl <<"Isi stack: ";
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