#ifndef _ListVoucher_H
#define _ListVoucher_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

struct voucherPulsa{
    string kode;
    string provider;
    int nominal;
    int harga;
    int stock;
    voucherPulsa *next;
};

struct linkList{
    voucherPulsa *first;
};

inline linkList createList(){
    linkList New;
    New.first = nullptr;
    return New;
};

inline voucherPulsa* alokasiList(string provider, string kode, 
    int nominal, int harga, int stock){
        voucherPulsa* New = new voucherPulsa;
        New->provider = provider;
        New->kode = kode;
        New->nominal = nominal;
        New->harga = harga;
        New->stock = stock;
        return New;
};

inline bool isEmptyList(linkList L){
    return (L.first == nullptr);
};

inline void addFirstList(linkList *L, string provider, string kode, 
    int nominal, int harga, int stock){

    voucherPulsa *New = alokasiList(provider, kode, nominal, harga, stock);
    if(isEmptyList(*(L))){
        L->first = New;
        return;
    };

    New->next = L->first;
    L->first = New;
};

inline void loadStoack(linkList *L, string File){
    ifstream file(File);

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

        addFirstList(L, provider, kode, 
            stoi(nominal), stoi(harga), stoi(stock));
    };

    file.close();
    return;

};

inline voucherPulsa* cariVoucher(linkList *L, string kode){
    if (isEmptyList(*(L))){
        return nullptr;
    };

    voucherPulsa *Temp = L->first;
    while(Temp != nullptr){
        if (Temp->kode == kode){
            return Temp;
        };
        Temp = Temp->next;
    };
    return nullptr;

};

inline void editStock(linkList *L, string kode, int minstock){
    if (isEmptyList(*(L))){
        return;
    };

    voucherPulsa *Temp = cariVoucher(L, kode);
    if (Temp != nullptr){
        Temp->stock = Temp->stock - minstock;
        return;
    };

    return;
};

inline void saveFileList(linkList L, string File){
    ofstream file(File);

    if (!file.is_open()){
        return;
    };

    voucherPulsa *Temp = L.first;
    while (Temp != nullptr){
        file << Temp->kode << ',' << Temp->provider << ',' 
        << Temp->nominal << ',' << Temp->harga << ',' << Temp->stock 
        << endl;
        Temp = Temp->next;
    };

    file.close();

};

inline void cetaklinkList(linkList L){
    if (isEmptyList(L)){
        return;
    };

    voucherPulsa *Temp = L.first;
    int counter = 0;

    while(Temp != nullptr){
        counter++;
        cout << counter << ". " << Temp->kode << "  " << Temp->provider 
        << "  " << Temp->nominal << "  " << Temp->harga << "  " << Temp->stock << endl;
        Temp = Temp->next;
    };
    cout << endl;
};
#endif