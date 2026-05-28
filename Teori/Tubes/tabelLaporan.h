#ifndef _Laporan_H
#define _Laporan_H
#include "externalUtils.h"
#include <iostream>
#include <ostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>

#define fileTabel "Teori/Tubes/db/dataTabel.txt"
#define fileSaveTabel "Teori/Tubes/db/dataTabel.txt"


using namespace std;
#define nmax 100

struct laporan{
    string tanggal;
    string kodePulsa;
    int jumlah;
    long long int total;
};

struct tabelLaporan{
    laporan Tabel[nmax + 1];
    int counter;
};

inline tabelLaporan createTabel(){
    tabelLaporan New;
    New.counter = 0;
    int counter = 0;
    for (counter = 0; counter <= nmax; counter++){
        New.Tabel[counter].jumlah = 0;
        New.Tabel[counter].total = 0;
        New.Tabel[counter].kodePulsa = " ";
        New.Tabel[counter].tanggal = " ";
    };
    return New;
};

inline bool isEmptyTabel(tabelLaporan T){
    return (T.counter <= 0);
};

inline bool isFullTabel(tabelLaporan T){
    return (T.counter == nmax);
};

inline laporan alokasiTabel(string tanggal,string kodePulsa,
    int jumlah, long long int total){

    laporan New;
    New.jumlah = jumlah;
    New.kodePulsa = kodePulsa;
    New.tanggal = tanggal;
    New.total = total;
    return New;

};

inline void pushTabel(tabelLaporan *T, string tanggal,string kodePulsa,
    int jumlah, long long int total){

    if (isEmptyTabel(*(T))){
        T->counter = 1;
        T->Tabel[T->counter] = alokasiTabel(tanggal, kodePulsa, jumlah, total);
        return;
    };

    if (!isFullTabel(*(T))){
        T->counter = T->counter + 1;
        T->Tabel[T->counter] = alokasiTabel(tanggal, kodePulsa, jumlah, total);
        return;
    };

    return;
};

inline bool searchKodeVoucher(tabelLaporan T, string kodePulsa){
    if (isEmptyTabel((T))){
        return false;
    };

    int counter = 0;
    for (counter = 1; counter <= T.counter; counter++ ){
        if (T.Tabel[counter].kodePulsa == kodePulsa){
            return true;
        };
    };

    return false;
};

inline void loadTabel(tabelLaporan *T){
    ifstream file(fileTabel);

    if (!file.is_open()){
        return;
    };

    string line;
    while (getline(file, line)){

        string tanggal, jam, kodePulsa, jumlah, totalHarga;
        stringstream ss(line);

        getline(ss, tanggal, ',');
        getline(ss, jam, ',');
        getline(ss, kodePulsa, ',');
        getline(ss, jumlah, ',');
        getline(ss, totalHarga);

        string date;
        if (!tanggal.empty() && !jam.empty()){
            date = tanggal + ',' + jam;
        };
        
        if (!date.empty() && !kodePulsa.empty() && isDigit(jumlah, false) && isDigit(totalHarga, false)){
            pushTabel(T, date, kodePulsa, stoi(jumlah), stoll(totalHarga));
        };
    };

    file.close();
    return;
};

inline void saveFileTabel(tabelLaporan T){
    ofstream file(fileSaveTabel);

    if (!file.is_open()){
        return;
    };

    int counter = 1;
    for (counter = 1; counter <= T.counter; counter++){
        file << T.Tabel[counter].tanggal << ','
        << T.Tabel[counter].kodePulsa << ','
        << T.Tabel[counter].jumlah << ','
        << T.Tabel[counter].total << endl;
    };

    file.close();

};

inline void cetakTabel(tabelLaporan T){
    if(isEmptyTabel(T)){
        return;
    };

    cout << string(3, '=') << " Laporan " << string(40, '=') << endl;
    printColumn("No", 5);
    printColumn("Tanggal", 20);
    printColumn("Kode", 10);
    printColumn("Qty", 8);
    printColumn("Total", 12);
    cout << endl;
    int countLoop = 1, counter = 0;
    
    for (countLoop = 1; countLoop <= T.counter; countLoop++){
        counter = counter + 1;
        printColumn(to_string(counter), 5);
        printColumn(T.Tabel[counter].tanggal, 20);
        printColumn(T.Tabel[counter].kodePulsa, 10);
        printColumn(to_string(T.Tabel[counter].jumlah), 8);
        printColumn(to_string(T.Tabel[counter].total), 12);
        cout << endl;
    };
    cout << endl;
};
#endif
