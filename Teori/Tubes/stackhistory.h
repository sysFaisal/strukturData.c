#ifndef _StackHistory_H
#define _StackHistory_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;
struct stackHistory{
    string idTransaksi;
    string namaPembeli;
    string noHP;
    string kodePulsa;
    int jumlah;
    int totalHarga;
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

inline stackHistory* alokasiHistory(string idTransaksi, string namaPembeli, string noHp, string kodePulsa, int jumlah, int totalHarga){
    stackHistory *New = new stackHistory;
    New->idTransaksi = idTransaksi;
    New->namaPembeli = namaPembeli;
    New->noHP = noHp;
    New->kodePulsa = kodePulsa;
    New->jumlah = jumlah;
    New->totalHarga = totalHarga;
    return New;
};

inline bool isEmptyList(History L){
    return (L.first == nullptr);
};

inline void push(History *L, string idTransaksi, string namaPembeli, string noHp, string kodePulsa, int jumlah, int totalHarga){
    stackHistory *New = alokasiHistory(idTransaksi, namaPembeli, noHp, kodePulsa, jumlah, totalHarga);
    if (isEmptyList(*(L))){
        L->first = New;
        L->counter = 1;
        return;
    };

    New->next = L->first;
    L->first = New;
    L->counter = L->counter + 1;
};

inline void pop(History *L){
    if (isEmptyList(*(L))){
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



#endif