#include <iostream>
#include "func.h"
#include <cstdlib>

int main (){
    Queue Q = initQueue();
    int pilihan = 0, x = 0;
    char lagi;
    
    do {
        system("clear");
        cout << endl <<"==================" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Cetak Queue" << endl;
        cout << "4. Count Queue" << endl;
        cout << "0. Keluar" << endl;
        cin >> pilihan;

        switch (pilihan) {

            case 1:
                cout << "=== Enqueue (999 untuk berhenti) ===" << endl;
                while (1) {
                    cout << "Masukan Element: ";
                    cin >> x;

                    if (x == 999) {
                        break;
                    }
                    
                    if(isFullQueue(&Q)){
                        cout << "Queue Penuh! Data gagal ditambahkan." << endl;
                        cout << "Tekan enter untuk lanjut...";
                        cin.ignore();
                        cin.get();
                        break;
                    }

                    enqueue(&Q, x);
                }
                break;

            case 2:

                cout << endl << "=== Dequeue ===" << endl;
                cout << "Isi Queue : ";
                cetakQueue(&Q);
                cout << endl;

                if (isEmptyQueue(&Q)) {
                    cout << "Queue Kosong!" << endl;
                    cout << "Tekan enter untuk lanjut...";
                    cin.ignore();
                    cin.get();
                    break;
                }

                do {
                    dequeue(&Q, &x);
                    cout << "Elemen yg dihapus:" << x << endl;

                    cout << "Isi Queue : ";
                    cetakQueue(&Q);
                    cout << endl;

                    if (isEmptyQueue(&Q)) {
                        cout << "Queue Kosong!" << endl;
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

                if (isEmptyQueue(&Q)) {
                    cout << "Queue Kosong!" << endl;
                    cout << "Tekan enter untuk lanjut...";
                    cin.ignore();
                    cin.get();
                    break;
                }

                cout << endl <<"Isi queue: ";
                cetakQueue(&Q);
                cout << endl;

                cout << "Tekan enter untuk lanjut...";
                cin.ignore();
                cin.get();
                break;
            
            case 4:
                
                if (isEmptyQueue(&Q)) {
                    cout << "Queue Kosong!" << endl;
                    cout << "Tekan enter untuk lanjut...";
                    cin.ignore();
                    cin.get();
                    break;
                }

                cout << "Jumlah Queue: " << CountQueue(&Q) << endl;
                
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