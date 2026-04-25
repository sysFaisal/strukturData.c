#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>
#include "func.h"
#include <sstream>

using namespace std;

SLL* initNode(){
    SLL *L = new SLL;
    L->first = nullptr;
    return L;
};

Node *addNode(int nim, string jurusan, string nama, float ipk){
    Node *New = new Node;
    New->nim = nim;
    New->Jurusan = jurusan;
    New->name = nama;
    New->ipk = ipk;
    New->Next = nullptr;
    return New;
};

void insertFirstNode(SLL *L, int nim, string jurusan, string nama, float ipk){
    
    Node *New = addNode(nim, jurusan, nama, ipk);

    if (L->first == NULL){
        L->first = New;
        return;
    };

    New->Next = L->first;
    L->first = New;
};

bool cekFile(ifstream &File){
    if (!File.is_open()){
        return false;
    };
    return true;
};

bool initall(SLL **L, ifstream &File){
    bool statLink = false;
    bool statFile = false;

    if (statLink == false){
        *L = initNode();
        statLink = true;
    };

    if (statFile == false){
        statFile = cekFile(File);
    };

    return statLink && statFile;
};

void printfile(ifstream &file){
    string line;
    while (getline(file, line)){
        cout << line << endl;
    };
};

void loadToNode(SLL *L, ifstream &file){
    if (!cekFile(file)){
        return;
    };

    string line;
    while (getline(file, line)){
        string nim, nama, jurusan, ipk;
        stringstream ss(line);

        getline(ss, nim, ',');
        getline(ss, nama, ',');
        getline(ss, jurusan, ',');
        getline(ss, ipk);

        insertFirstNode(L, stoi(nim), jurusan, nama, stof(ipk));
    };
};

void cetakNode(SLL *L){
    if (L->first == nullptr){
        cout << "Data Kosong" << endl;
        return;
    };

    Node *Temp = L->first;
    while(Temp != nullptr){
        cout << Temp->nim << endl;
        cout << Temp->name << endl;
        cout << Temp->Jurusan << endl;
        cout << Temp->ipk << endl;
        cout << endl;
        Temp = Temp->Next;
    };
    cout << "NULL" << endl;
};

void deleteFirstNode(SLL *L){
    if (L->first == nullptr){
        cout << "Data Kosong" << endl;
        return;
    };

    Node *Temp = L->first;
    L->first = L->first->Next;
    delete Temp;
};

void filterNode(SLL *L, float ipk){
    if (L->first == nullptr){
        cout << "Data Kosong" << endl;
        return;
    };

    while (L->first->ipk < ipk && L->first->Next != nullptr){
        deleteFirstNode(L);
    };

    Node *Curr = L->first;
    Node *Temp = nullptr;
    Node *Prev = nullptr;

    while (Curr != nullptr){

        while (Curr != nullptr && Curr->ipk < ipk){
            Prev->Next = Curr->Next;
            delete Curr;
            Curr = Prev->Next;
        }

        if (Curr != nullptr){
            Prev = Curr;
            Curr = Curr->Next;
        }
    }
};

void saveToFile(SLL *L, ofstream &file){
    if (L->first == nullptr){
        cout << "Data Kosong" << endl;
        return;
    };

    if (!file.is_open()){
        cout << "File Kosong" << endl;
        return;
    };

    Node *Temp = L->first;
    while (Temp != nullptr){
        file << Temp->nim << ',' << Temp->name << ',' << Temp->Jurusan << ',' << Temp->ipk << endl;
        Temp = Temp->Next;
    };

    file.close();
};