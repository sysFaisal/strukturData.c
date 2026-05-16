#include <stdlib.h>
#include <fstream>
#include <string>
#include <stdbool.h>
#include "global_func.h"
#include <iostream>

using namespace std;

int main(){

    string readFile[2], writeFile[2];
    readFile[0] = "Teori/Tugas/mhslink/a_dataMhs.txt";
    readFile[1] = "Teori/Tugas/mhslink/data/hasil.txt";
    writeFile[0] = "Teori/Tugas/mhslink/data/hasil.txt";
    writeFile[1] = "Teori/Tugas/mhslink/data/hasil.txt";
    int totalFileRead = 2, totalFileWrite = 2;

    if(!CekFileAll(totalFileRead, totalFileWrite, readFile, writeFile)){
        cout << "gagal";
        return 0;
    };
    
    ifstream readSingle(readFile[0]);
    ifstream readDouble(readFile[1]);
    ofstream writeSingle(writeFile[0]);
    ofstream writeDouble(writeFile[1]);

    SLL S = initSingle();
    DLL D = initDouble();

    int pilihan = -1;
    do {
        system("clear");
        cout << endl <<"==================" << endl;
        cout << "1. Load File to Node (SLL) " << endl;
        cout << "2. Filter Node (SLL) " << endl;
        cout << "3. Cetak Node (SLL) " << endl;
        cout << "4. Save Node to File (SLL) " << endl;
        cout << "5. Load File to Node (DLL)" << endl;
        cout << "6. Sort Node (DLL)" << endl;
        cout << "7. Cetak Node (DLL)" << endl;
        cout << "8. Save Node to File (DLL)" << endl;
        cout << "9. Clear File" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {

            case 1:
                cout << endl <<"Load File to Node (SLL)" << endl;
                loadToNodeSingle(&S, readFile[0]);
                cout << endl <<"Tekan enter untuk lanjut...";
                cin.ignore();
                cin.get();
                break;

            case 2:
                cout << endl <<"Filter Node (SLL)" << endl;
                cout << "Node yang sebelum difilter :" << endl;
                cetakNodeSingle(&S);
                filterNodeSingle(&S, 3.7);
                cout << endl << "Node yang sudah di filter :" << endl;
                cetakNodeSingle(&S);
                cout << endl <<"Tekan enter untuk lanjut...";
                cin.ignore();
                cin.get();

                break;

            case 3:
                cout << endl <<"Cetak Node (SLL)" << endl;
                cetakNodeSingle(&S);
                cout << endl << "Tekan enter untuk lanjut...";
                cin.ignore();
                cin.get();

                break;

            case 4:
                cout << endl <<"Save Node to File (SLL)" << endl;
                saveToFileSingle(&S, writeFile[0]);
                cout << endl << "Tekan enter untuk lanjut...";
                cin.ignore();
                cin.get();                
                break;

            case 5:
                cout << endl <<"Load File to Node (DLL)" << endl;
                loadtoNodeDouble(&D, readFile[1]);
                cout << endl <<"Tekan enter untuk lanjut...";
                cin.ignore();
                cin.get();   
                break;

            case 6:
                cout << endl <<"Sort Node (DLL)" << endl;
                cout << "Node yang sebelum disorting :" << endl;
                cetakNodeDouble(&D);
                sortNodeDouble(&D);
                cout << endl << "Node yang sudah disorting :" << endl;
                cetakNodeDouble(&D);
                cout << endl <<"Tekan enter untuk lanjut...";
                cin.ignore();
                cin.get();  
                break;

            case 7:
                cout << endl <<"Cetak Node (DLL)" << endl;
                cetakNodeDouble(&D);
                cout << endl <<"Tekan enter untuk lanjut...";
                cin.ignore();
                cin.get();  
                break;

            case 8:
                cout << endl <<"Save Node to File (DLL)" << endl;
                saveToFileDouble(&D, writeFile[1]);
                cout << endl <<"Tekan enter untuk lanjut...";
                cin.ignore();
                cin.get();  
                break;

            case 9:
                cout << endl <<"Clear File (DLL)" << endl;
                loopclearFile(totalFileWrite, writeFile);
                cout << endl <<"Tekan enter untuk lanjut...";
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






    }  while (pilihan != 0);

};
