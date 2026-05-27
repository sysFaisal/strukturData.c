#ifndef _ListVoucher_H
#define _ListVoucher_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;
#define fileVouncher "Teori/Tubes/dataVoucher.txt"

struct voucherPulsa{
    string kode;
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
        New->kode = kode;
        New->nominal = nominal;
        New->harga = harga;
        New->stock = stock;
        return New;
};

inline bool isEmptyList(linkList L){
    return (L.front == nullptr);
};

inline int getJumlahList(linkList L){
    return (L.counter);
};

inline void saveFileList(linkList L){
    ofstream file(fileVouncher);

    if (!file.is_open()){
        return;
    };

    voucherPulsa *Temp = L.front;
    while (Temp != nullptr){
        file << Temp->kode << ',' << Temp->provider << ',' 
        << Temp->nominal << ',' << Temp->harga << ',' << Temp->stock 
        << endl;
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

        addLastList(L, provider, kode, 
            stoi(nominal), stoi(harga), stoi(stock));
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
        int VeryTemp = Temp->stock - minstock;

        if (VeryTemp <= 0){
            cout << "Gagal Melakukan Transaksi!!" << endl;
            return;
        };

        Temp->stock = VeryTemp;
        saveFileList(*(L));
        return;
    };

    return;
};


inline void cetaklinkList(linkList L){
    if (isEmptyList(L)){
        return;
    };
    
    voucherPulsa *Temp = L.front;
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

