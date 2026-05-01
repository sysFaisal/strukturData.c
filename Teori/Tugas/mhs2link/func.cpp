#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>
#include <stdbool.h>
#include "func.h"

using namespace std;

DLL* initDLL(){
    DLL *New = new DLL;
    New->first = NULL;
    return New;
};

Node* addNode(int nim, string nama, string jurusan, float ipk){
    Node *New = new Node;
    New->nim = nim;
    New->name = nama;
    New->jurusan = jurusan;
    New->ipk = ipk;
    New->Next = nullptr;
    New->Prev = nullptr;
    return New;
};

bool cekFile(ifstream &File){
    if (!File.is_open()){
        return false;
    };
    return true;
};

bool initall(DLL **L, ifstream &File){
    bool statLink = false;
    bool statFile = false;

    if (statLink == false){
        *L = initDLL();
        statLink = true;
    };

    if (statFile == false){
        statFile = cekFile(File);
    };

    return statLink && statFile;
};

void insertFirstNode(DLL *L, int nim, string nama, string jurusan, float ipk){
    Node *New = addNode(nim, nama, jurusan, ipk);

    if (L->first == NULL){
        L->first = New;
        return;
    };
    Node *Temp = L->first;
    Temp->Prev = New; 
    New->Next = Temp;
    L->first = New;

};

void loadtoNode(DLL *L, ifstream &file){
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

        insertFirstNode(L, stoi(nim), nama, jurusan, stof(ipk));
    };

    return;
};

void sortNode(DLL *L){
    if (L->first == nullptr){
        return;
    };

    if (L->first->Next == nullptr){
        cout << "Data Cuma ada 1" << endl;
        return;
    };

    Node *Sorted = nullptr;

    while (L->first != nullptr){
        Node *max = L->first;
        Node *Temp = L->first->Next;

        while(Temp != nullptr){
            if (Temp->ipk < max->ipk){
                max = Temp;
            };
            Temp = Temp->Next;
        };

        if (max->Prev != nullptr){
            max->Prev->Next = max->Next;
        } else {
            L->first = max->Next;
        }

        if (max->Next != nullptr){
            max->Next->Prev = max->Prev;
        };


        max->Next = Sorted;
        max->Prev = nullptr;

        if (Sorted != nullptr){
            Sorted->Prev = max;
        };

        Sorted = max;
        
    };

    L->first = Sorted;

};

void cetakNode(DLL *L){
    if (L->first == nullptr){
        cout << "Data Kosong" << endl;
        return;
    };

    Node *Temp = L->first;
    while(Temp != nullptr){
        cout << Temp->nim << endl;
        cout << Temp->name << endl;
        cout << Temp->jurusan<< endl;
        cout << Temp->ipk << endl;
        cout << endl;
        Temp = Temp->Next;
    };
    cout << "NULL" << endl;
};

void saveToFile(DLL *L, ofstream &file){
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
        file << Temp->nim << ',' << Temp->name << ',' << Temp->jurusan << ',' << Temp->ipk << endl;
        Temp = Temp->Next;
    };

    file.close();
};

/*
void insertLastNode(DLL *L, int data){

    Node *New = addNode(data);

    if (L->first == NULL){
        L->first = New;
        return;
    };

    Node *Temp = L->first;
    
    while (Temp->Next != NULL){
        Temp = Temp->Next;
    };

    New->Prev = Temp;
    Temp->Next = New;

};


void insertTargetNode(DLL *L, int data, int position){

    if (L->first == nullptr){
        insertFirstNode(L, data);
        return;
    };

    Node *Temp = L->first;
    int counter = 0;

    if (position <= 0){
        return;
    };

    if (position == 1){
        insertFirstNode(L, data);
        return;
    };

    while(Temp != nullptr){

        counter = counter + 1;
        if (position == counter){

            Node *New = addNode(data);

            New->Prev = Temp->Prev; 
            New->Next = Temp;
            New->Prev->Next = New;
            New->Next->Prev = New;
            
            return;
        };
        Temp = Temp->Next;

    };

    if (position > counter){
        insertLastNode(L, data);
        return;
    };
};

void cetakNextNode(DLL *L){

    if (L->first == NULL){
        return;
    };

    Node *Temp = L->first;
    while(Temp->Next != NULL){
        printf("%d -> ", Temp->data);
        Temp = Temp->Next;
    };
    printf("%d -> NULL\n", Temp->data);

};

void cetakPrevNode(DLL *L){

    if (L->first == NULL){
        return;
    };
    
    Node *Temp = L->first;
    while(Temp->Next != NULL){
        Temp = Temp->Next;
    };

    int flag = 0;
    while(Temp->Prev != NULL){
        if (flag == 0){
            printf("NULL <- %d", Temp->data);
            flag = 1;
        }else {
            printf(" <- %d", Temp->data);
        };
        Temp = Temp->Prev;
    };
    printf(" <- %d\n", Temp->data);

};

void deleteLastNode(DLL *L){

    if (L->first == nullptr){
        return;
    };

    Node *Temp = L->first;
    Node *Temp1 = nullptr;

    while(Temp->Next != nullptr){
        Temp1 = Temp;
        Temp = Temp->Next;     
    };

    Temp1->Next = nullptr;
    Temp->Prev = nullptr;
    free(Temp);
    Temp = NULL;
    
};

void deleteFirstNode(DLL *L){

    if (L->first == nullptr){
        return;
    };

    Node *Temp = L->first;
    Node *Temp1 = nullptr;

    Temp1 = Temp->Next;
    Temp1->Prev = nullptr;
    Temp->Next = nullptr;
    L->first = Temp1;
    free(Temp);
    Temp = NULL;
};

void deleteTargetNode(DLL *L, int target){

    if (L->first == nullptr){
        return;
    };

    Node *Temp = L->first;

    if (Temp->data == target){
        deleteFirstNode(L);
        return;
    };

    while((Temp != nullptr)){
        if (Temp->data == target){

            if (Temp->Next == nullptr){
                deleteLastNode(L);
                return;
            };

            Temp->Prev->Next = Temp->Next;
            Temp->Next->Prev = Temp->Prev;
            Temp->Next = nullptr;
            Temp->Prev = nullptr;

            free(Temp);
            Temp = NULL;
            return;
        };
        Temp = Temp->Next;
    };

    printf("Tidak ada data dengan data %d\n", target);
};  
*/