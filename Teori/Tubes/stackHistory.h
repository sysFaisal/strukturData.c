#ifndef _StackHistory_H
#define _StackHistory_H
#include <iostream>
#include <ostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include "externalUtils.h"

using namespace std;
#define fileHistory "Teori/Tubes/db/dataHistory.txt"
#define fileSaveHistory "Teori/Tubes/dataHistory.txt"

struct stackHistory{
    string idTransaksi;
    string namaPembeli;
    string noHP;
    string kodePulsa;
    string tanggal;
    int jumlah;
    long long int totalHarga;
    string status;
    stackHistory *next;
};

struct History{
    stackHistory *first;
    int counter;
};

inline History createHistory(){
    History New;
    New.first = nullptr;
    New.counter = 0;
    return New;
};

inline stackHistory* alokasiHistory(string idTransaksi, string namaPembeli, string noHp, string kodePulsa, string tanggal, int jumlah,
    long long int totalHarga, string status){
    stackHistory *New = new stackHistory;
    New->idTransaksi = idTransaksi;
    New->namaPembeli = namaPembeli;
    New->noHP = noHp;
    New->kodePulsa = kodePulsa;
    New->tanggal = tanggal;
    New->jumlah = jumlah;
    New->totalHarga = totalHarga;
    New->status = status;
    return New;
};

inline bool isEmptyHistory(History L){
    return (L.first == nullptr);
};

inline bool pushHistory(History *L, string idTransaksi, string namaPembeli, string noHp, string kodePulsa, string tanggal,
    int jumlah, long long int totalHarga, string status){
    stackHistory *New = alokasiHistory(idTransaksi, namaPembeli, noHp, kodePulsa, tanggal, jumlah, totalHarga, status);
    if (isEmptyHistory(*(L))){
        L->first = New;
        L->counter = 1;
        return true;
    };

    New->next = L->first;
    L->first = New;
    L->counter = L->counter + 1;
    return true;
};

inline void loadHistory(History *L){
    ifstream file(fileHistory);

    if (!file.is_open()){
        return;
    };

    string line;
    while (getline(file, line)){

        string idTransaksi, nama, noHP, kodePulsa, jumlah, totalHarga, Tanggal, jam, status;
        stringstream ss(line);

        getline(ss, idTransaksi, ',');
        getline(ss, nama, ',');
        getline(ss, noHP, ',');
        getline(ss, kodePulsa, ',');
        getline(ss, jumlah, ',');
        getline(ss, totalHarga, ',');
        getline(ss, Tanggal, ',');
        getline(ss, jam, ',');
        getline(ss, status);

        if (!idTransaksi.empty() && !nama.empty() && isDigit(jumlah, false) && isDigit(totalHarga, false)){
            string date = Tanggal + "," + jam;
            pushHistory(L, idTransaksi, nama, noHP, kodePulsa, date, stoi(jumlah), stoll(totalHarga), status);
        }
    };

    file.close();
    return;
};

inline void saveFileHistory(History L){
    ofstream file(fileSaveHistory);

    if (!file.is_open()){
        return;
    };

    //TRX905431,Salsa,081377744455,SF25,2,54000,27/5/2026,21:27
    stackHistory *Temp = L.first;
    while (Temp != nullptr){
        file << Temp->idTransaksi << ','
        << Temp->namaPembeli << ','
        << Temp->noHP << ','
        << Temp->kodePulsa << ','
        << Temp->jumlah << ','
        << Temp->totalHarga << ','
        << Temp->tanggal << ','
        << Temp->status << endl;
        Temp = Temp->next;
    };

    file.close();
};

inline void pop(History *L){
    if (isEmptyHistory(*(L))){
        return;
    };

    stackHistory *Temp = L->first;

    if (L->first->next == nullptr){
        L->first = nullptr;
        L->counter = 0;
        delete Temp;
        return;
    };

    L->first = L->first->next;
    L->counter = L->counter - 1;
    delete Temp;
};

inline void cetakHistory(History L){
    if(isEmptyHistory(L)){
        return;
    };

    cout << string(3, '=') << " History " << string(100,'=') << endl;
    printColumn("No", 5);
    printColumn("ID", 15);
    printColumn("Nama", 15);
    printColumn("No HP", 18);
    printColumn("Kode", 10);
    printColumn("Qty", 8);
    printColumn("Total", 12);
    printColumn("Tanggal", 20);
    printColumn("Status", 12);

    cout << endl;

    stackHistory *Temp = L.first;
    int counter = 0;
    //TRX905431,Salsa,081377744455,SF25,2,54000,27/5/2026,21:27
    while (Temp != nullptr){
        counter = counter + 1;

        printColumn(to_string(counter) + ".", 5);
        printColumn(Temp->idTransaksi, 15);
        printColumn(Temp->namaPembeli, 15);
        printColumn(Temp->noHP, 18);
        printColumn(Temp->kodePulsa, 10);
        printColumn(to_string(Temp->jumlah), 8);
        printColumn(to_string(Temp->totalHarga), 12);
        printColumn(Temp->tanggal, 20);
        printColumn(Temp->status, 12);
        cout << endl;

        Temp = Temp->next;
    };
    cout << endl;
};

#endif
