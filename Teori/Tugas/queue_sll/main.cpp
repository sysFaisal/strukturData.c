#include <iostream>
#include "func.h"
#include <cstdlib>

int main (){
    Queue *Q = initQueue();
    int pilihan = 0;
    float sizeMB;
    char lagi;
    string namaFile;
    do {
        system("clear");
        cout << endl <<"==================" << endl;
        cout << "1. Download File (Enqueue)" << endl;
        cout << "2. Proses File (Dequeue)" << endl;
        cout << "3. Cetak Semua File" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;

        switch (pilihan) {

            case 1:
                cout << endl << "=== Enqueue (Download) ===" << endl;
                while (1) {
                    cout << "Masukan Nama File: ";
                    cin >> namaFile;
                    cout << "Masukan Size File (MB): ";
                    cin >> sizeMB;

                    cout << "Lagi? (y/n): ";
                    cin >> lagi;

                    enqueue(Q, sizeMB, namaFile);

                    if (lagi == 'n' || lagi == 'N') {
                        break;
                    }

                }
                break;

            case 2:

                cout << endl << "=== Dequeue (Proses) ===" << endl;
                cout << "Isi File dalam Queue : ";
                cetakQueue(Q);
                cout << endl;

                if (isEmptyQueue(Q)) {
                    cout << endl << "Queue Kosong!" << endl;
                    cout << "Tekan enter untuk lanjut...";
                    cin.ignore();
                    cin.get();
                    break;
                }

                do {

                    cout << "Proses? (y/n): ";
                    cin >> lagi;

                    if (lagi == 'n' || lagi == 'N') {
                        break;
                    }

                    if (isEmptyQueue(Q)) {
                        cout << "Queue Kosong!" << endl;
                        cout << "Tekan enter untuk lanjut...";
                        cin.ignore();
                        cin.get();
                        break;
                    }

                    dequeue(Q, &sizeMB, &namaFile);
                    cout << "File yg ditelah didownload: "<< endl << namaFile << "  "<< sizeMB << endl;

                    if(!isEmptyQueue(Q)){
                        cout << endl << "Isi File dalam Queue : ";
                        cetakQueue(Q);
                        cout << endl;
                    }else {
                        cout << endl;
                    };


                } while (lagi == 'y' || lagi == 'Y');

                break;

            case 3:

                if (isEmptyQueue(Q)) {
                    cout << endl << "Queue Kosong!" << endl;
                    cout << "Tekan enter untuk lanjut...";
                    cin.ignore();
                    cin.get();
                    break;
                }

                cout << endl <<"Isi File dalam Queue: ";
                cetakQueue(Q);
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
