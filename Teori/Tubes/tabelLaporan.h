#ifndef _Laporan_H
#define _Laporan_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;
#define nmax 100

struct laporan{
    string tanggal;
    string kodePulsa;
    int jumlah;
    int total;
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
    int jumlah, int total){

    laporan New;
    New.jumlah = jumlah;
    New.kodePulsa = kodePulsa;
    New.tanggal = tanggal;
    New.total = total;
    return New;

};

inline void pushTabel(tabelLaporan *T, string tanggal,string kodePulsa,
    int jumlah, int total){

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

inline void saveTabel(tabelLaporan T, string File){
    ofstream file(File);

    if (!file.is_open()){
        return;
    };

    int counter = 0;
    for (counter = 1; counter <= nmax; counter++){
        file << T.Tabel[counter].tanggal << ',' << T.Tabel[counter].kodePulsa << ','
        << T.Tabel[counter].jumlah << ',' << T.Tabel[counter].jumlah << endl;
    };

    file.close();
};

#endif
