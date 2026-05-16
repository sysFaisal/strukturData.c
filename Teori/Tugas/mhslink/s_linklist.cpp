#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>
#include "global_func.h"
#include <sstream>

using namespace std;

SLL initSingle(){
    SLL L;
    L.first = nullptr;
    return L;
};

NodeSingle *addNodeSingle(int nim, string jurusan, string nama, float ipk){
    NodeSingle *New = new NodeSingle;
    New->nim = nim;
    New->Jurusan = jurusan;
    New->name = nama;
    New->ipk = ipk;
    New->Next = nullptr;
    return New;
};

void insertFirstNodeSingle(SLL *L, int nim, string jurusan, string nama, float ipk){

    NodeSingle *New = addNodeSingle(nim, jurusan, nama, ipk);

    if (L->first == NULL){
        L->first = New;
        return;
    };

    New->Next = L->first;
    L->first = New;
};


void printfileSingle(ifstream &file){
    string line;
    while (getline(file, line)){
        cout << line << endl;
    };
};

void loadToNodeSingle(SLL *L, string readFile){
    ifstream file(readFile);

    if(!openFile(file)){
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

        insertFirstNodeSingle(L, stoi(nim), jurusan, nama, stof(ipk));
    };

    file.close();
};

void cetakNodeSingle(SLL *L){
    if (L->first == nullptr){
        cout << "Data Kosong" << endl;
        return;
    };

    cout << "Single Linked List" << endl;
    int counter = 0;
    NodeSingle *Temp = L->first;
    while(Temp != nullptr){
        counter = counter + 1;
        cout << counter << ". " 
        << Temp->nim << " " 
        <<Temp->name << " " 
        << Temp->Jurusan << " "
        << Temp->ipk << endl;
        Temp = Temp->Next;
    };
    cout << "NULL" << endl;
};

void deleteFirstNodeSingle(SLL *L){
    if (L->first == nullptr){
        cout << "Data Kosong" << endl;
        return;
    };

    NodeSingle *Temp = L->first;
    L->first = L->first->Next;
    delete Temp;
};

void filterNodeSingle(SLL *L, float ipk){
    if (L->first == nullptr){
        cout << "Data Kosong" << endl;
        return;
    };

    while (L->first != nullptr && L->first->ipk < ipk){
        deleteFirstNodeSingle(L);
    };

    if (L->first == nullptr){
        return;
    };

    NodeSingle *Prev = L->first;
    NodeSingle *Curr = L->first->Next;

    while (Curr != nullptr){
        while (Curr != nullptr && Curr->ipk < ipk){
            NodeSingle *VeryTemp = Curr->Next;
            Prev->Next = VeryTemp;
            delete Curr;
            Curr = VeryTemp;
        };

        if (Curr != nullptr){
            Prev = Curr;
            Curr = Curr->Next;
        }
    };

};

void saveToFileSingle(SLL *L, string writeFile){
    ofstream file (writeFile);
    
    if (L->first == nullptr){
        cout << "Data Kosong" << endl;
        return;
    };

    if (!file.is_open()){
        cout << "File Kosong" << endl;
        return;
    };

    NodeSingle *Temp = L->first;
    while (Temp != nullptr){
        file << Temp->nim << ',' << Temp->name << ',' << Temp->Jurusan << ',' << Temp->ipk << endl;
        Temp = Temp->Next;
    };

    file.close();
};

/*
    void sortNode(SLL *L){
        if (L->first == nullptr){
            cout << "Data Kosong" << endl;
            return;
        };

        NodeSingle *Curr = L->first;
        NodeSingle Boiler;

        while (Curr != nullptr){
            NodeSingle *Fix = Curr;
            NodeSingle *Temp = Curr->Next;

            while (Temp != nullptr){
                if (Fix->ipk < Temp->ipk){
                    Fix = Temp;
                };
                Temp = Temp->Next;
            };

            if (Fix != Curr){
                Boiler.ipk = Curr->ipk;
                Boiler.Jurusan = Curr->Jurusan;
                Boiler.name = Curr->name;
                Boiler.nim = Curr->nim;

                Curr->ipk = Fix->ipk;
                Curr->Jurusan = Fix->Jurusan;
                Curr->name = Fix->name;
                Curr->nim = Fix->nim;

                Fix->ipk = Boiler.ipk;
                Fix->Jurusan = Boiler.Jurusan;
                Fix->name = Boiler.name;
                Fix->nim = Boiler.nim;
            };

            Curr = Curr->Next;
        };
    };
 */
