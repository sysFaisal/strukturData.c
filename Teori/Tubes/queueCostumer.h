#ifndef _QueueCostumer_H
#define _QueueCostumer_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include "externalUtils.h"

using namespace std;
#define fileQueue "Teori/Tubes/db/dataQueue.txt"

struct QueueCos{
    string nama;
    string noHP;
    string kodePulsa;
    string tanggal;
    int jumlah;
    QueueCos *next;
};

struct Costumer{
    QueueCos *front;
    QueueCos *rear;
    int counter;
};

inline Costumer createQueue(){
    Costumer New;
    New.front = nullptr;
    New.rear = nullptr;
    return New;
};

inline QueueCos* alokasiQueue(string nama, string noHp, string kodePulsa, string Tanggal ,int jumlah){
    QueueCos *New = new QueueCos;
    New->nama = nama;
    New->noHP = noHp;
    New->kodePulsa = kodePulsa;
    New->jumlah = jumlah;
    New->tanggal = Tanggal;
    New->next = nullptr;
    return New;
};

inline bool isEmptyQueue(Costumer L){
    return (L.front == nullptr);
};

inline void enqueue(Costumer *L, string nama, string noHp, string kodePulsa, string Tanggal ,int jumlah){
    QueueCos *New = alokasiQueue(nama, noHp, kodePulsa, Tanggal, jumlah);
    if (isEmptyQueue(*(L))){
        L->front = New;
        L->rear = New;
        return;
    };

    L->rear->next = New;
    L->rear = New;
};

inline void loadQueue(Costumer *L){
    ifstream file(fileQueue);

    if (!file.is_open()){
        return;
    };

    string line;
    while (getline(file, line)){

        string nama, noHP, kodeVoucher, Tanggal, jam, jumlah;
        stringstream ss(line);

        getline(ss, nama, ',');
        getline(ss, noHP, ',');
        getline(ss, kodeVoucher, ',');
        getline(ss, Tanggal, ',');
        getline(ss, jam, ',');
        getline(ss, jumlah);

        if (!nama.empty() && 
            !noHP.empty() && 
            !kodeVoucher.empty() && 
            !Tanggal.empty() &&
            !jam.empty() && 
            isDigit(jumlah, false)){

            string date = Tanggal + "," + jam;
            enqueue(L, nama, noHP, kodeVoucher, date , stoi(jumlah));
        };
        
    };

    file.close();
    return;
};

inline bool dequeue(Costumer *L, string *nama, string *noHp, string *kodePulsa, int *jumlah){

    if (isEmptyQueue(*(L))){
        return false;
    };

    QueueCos *Temp = L->front;
    *nama = Temp->nama;
    *noHp = Temp->noHP;
    *kodePulsa = Temp->kodePulsa;
    *jumlah = Temp->jumlah;

    if (L->front->next == nullptr){
        L->front = nullptr;
        L->rear = nullptr;
        free (Temp);
        return true;
    };

    L->front = L->front->next;
    free (Temp);
    return true;
};

inline void cetakCostumer(Costumer L){
    if (isEmptyQueue(L)){
        return;
    };

    cout << string(3,'=') << " Daftar Antrian " << string(50,'=') << endl;

    printColumn("No", 5);
    printColumn("Nama", 14);
    printColumn("No HP", 16);
    printColumn("Kode", 11);
    printColumn("Qty", 7);
    printColumn("Tanggal", 20);

    cout << endl;

    int counter = 0;
    QueueCos *Temp = L.front;

    while(Temp != nullptr){
        counter = counter + 1;

        printColumn(to_string(counter) + ".", 5);
        printColumn(Temp->nama, 14);
        printColumn(Temp->noHP, 16);
        printColumn(Temp->kodePulsa, 11);
        printColumn(to_string(Temp->jumlah), 7);
        printColumn(Temp->tanggal, 20);
        cout << endl;

        Temp = Temp->next;
    };
    cout << endl;
};


#endif
