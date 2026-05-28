#ifndef _ListVoucher_H
#define _ListVoucher_H
#include <ios>
#include <iostream>
#include <iterator>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include "externalUtils.h"

using namespace std;
#define fileVouncher "Teori/Tubes/db/dataVoucher.txt"
#define fileSaveVouncher "Teori/Tubes/db/dataVoucher.txt"

struct voucherPulsa{
    string kodePulsa;
    string provider;
    int nominal;
    int harga;
    int stock;
    voucherPulsa *next;
};

struct linkList{
    voucherPulsa *front;
    voucherPulsa *rear;
    int counter;
};

inline linkList createList(){
    linkList New;
    New.front = nullptr;
    New.rear = nullptr;
    New.counter = 0;
    return New;
};

inline voucherPulsa* alokasiList(string provider, string kode,
    int nominal, int harga, int stock){
        voucherPulsa* New = new voucherPulsa;
        New->provider = provider;
        New->kodePulsa = kode;
        New->nominal = nominal;
        New->harga = harga;
        New->stock = stock;
        return New;
};


inline bool isEmptyList(linkList L){
    return (L.front == nullptr);
};

inline bool cariKodePulsa(linkList L, string kodePulsa){
    if (isEmptyList(L)){
        return false;
    };

    voucherPulsa *Temp = L.front;
    while(Temp != nullptr){
        if(Temp->kodePulsa == kodePulsa){
            return true;
        };
        Temp = Temp->next;
    };

    return false;
};

inline int getJumlahList(linkList L){
    return (L.counter);
};

inline void saveFileList(linkList L){
    ofstream file(fileSaveVouncher);

    if (!file.is_open()){
        return;
    };

    voucherPulsa *Temp = L.front;
    while (Temp != nullptr){
        file << Temp->kodePulsa << ','
        << Temp->provider << ','
        << Temp->nominal << ','
        << Temp->harga << ','
        << Temp->stock << endl;
        Temp = Temp->next;
    };

    file.close();
};

inline void addFirstList(linkList *L, string provider, string kode,
    int nominal, int harga, int stock){

    voucherPulsa *New = alokasiList(provider, kode, nominal, harga, stock);
    if(isEmptyList(*(L))){
        L->front = New;
        L->rear = New;
        L->counter = 1;
        return;
    };


    New->next = L->front;
    L->front = New;
    L->counter = L->counter + 1;

};

inline void addLastList(linkList *L, string provider, string kode,
    int nominal, int harga, int stock){

    voucherPulsa *New = alokasiList(provider, kode, nominal, harga, stock);
    if (isEmptyList(*(L))){
        addFirstList(L, provider, kode, nominal, harga, stock);
        return;
    };

    L->rear->next = New;
    L->rear = New;
    L->counter = L->counter + 1;
};

inline void loadStoack(linkList *L){
    ifstream file(fileVouncher);

    if (!file.is_open()){
        return;
    };

    string line;
    while (getline(file, line)){

        string kode, provider, nominal, harga, stock;
        stringstream ss(line);

        getline(ss, kode, ',');
        getline(ss, provider, ',');
        getline(ss, nominal, ',');
        getline(ss, harga, ',');
        getline(ss, stock);

        if (
            !kode.empty() &&
            !provider.empty() &&
            isDigit(nominal, true) &&
            isDigit(harga, true) &&
            isDigit(stock, true)
            ){

            addLastList(L, provider, kode,
            stoi(nominal), stoi(harga), stoi(stock));

        };

    };

    file.close();
    return;

};

inline voucherPulsa* cariVoucher(linkList *L, string kode){
    if (isEmptyList(*(L))){
        return nullptr;
    };

    voucherPulsa *Temp = L->front;
    while(Temp != nullptr){
        if (Temp->kodePulsa == kode){
            return Temp;
        };
        Temp = Temp->next;
    };
    return nullptr;
};

inline bool kurangiStock(linkList *L, string kode, int minstock, int *actualSell, int *harga){
    if (isEmptyList(*(L))){
        return false;
    };

    voucherPulsa *Temp = cariVoucher(L, kode);
    if (Temp != nullptr){

        if (Temp->stock < minstock){
            *actualSell = Temp->stock;
            *harga = Temp->harga;
            Temp->stock = 0;
            return true;
        };

        Temp->stock = Temp->stock - minstock;
        *harga = Temp->harga;
        *actualSell = minstock;
        return true;
    };


    return false;
};

inline void cetaklinkList(linkList L){
    if (isEmptyList(L)){
        return;
    };

    voucherPulsa *Temp = L.front;
    int counter = 0;

    cout << string(3, '=') << " List Voucher " << string(48, '=') << endl;

    printColumn("No", 5);
    printColumn("Kode Pulsa", 12);
    printColumn("Provider", 18);
    printColumn("Nominal", 12);
    printColumn("Harga", 12);
    printColumn("Stock", 8);
    cout << endl;

    while(Temp != nullptr){
        counter++;
        printColumn(to_string(counter), 5);
        printColumn(Temp->kodePulsa, 12);
        printColumn(Temp->provider, 18);
        printColumn(to_string(Temp->nominal), 12);
        printColumn(to_string(Temp->harga), 12);
        printColumn(to_string(Temp->stock), 8);
        cout << endl;
        Temp = Temp->next;
    };
    cout << endl;
};
#endif
