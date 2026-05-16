#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>
#include <stdbool.h>
#include "global_func.h"

using namespace std;

DLL initDouble(){
    DLL New;
    New.first = NULL;
    return New;
};

NodeDouble* addNodeDouble(int nim, string nama, string jurusan, float ipk){
    NodeDouble *New = new NodeDouble;
    New->nim = nim;
    New->name = nama;
    New->jurusan = jurusan;
    New->ipk = ipk;
    New->Next = nullptr;
    New->Prev = nullptr;
    return New;
};

void insertFirstNodeDouble(DLL *L, int nim, string nama, string jurusan, float ipk){
    NodeDouble *New = addNodeDouble(nim, nama, jurusan, ipk);

    if (L->first == NULL){
        L->first = New;
        return;
    };
    NodeDouble *Temp = L->first;
    Temp->Prev = New;
    New->Next = Temp;
    L->first = New;

};

void printfileDouble(string readFile){
    ifstream file(readFile);

    if(!openFile(file)){
        return;
    };

    string line;
    while (getline(file, line)){
        cout << line << endl;
    };

    file.close();
};

void loadtoNodeDouble(DLL *L, string readFile){
    ifstream file(readFile);

    if (!openFile(file)){
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

        insertFirstNodeDouble(L, stoi(nim), nama, jurusan, stof(ipk));
    };

    file.close();
    return;
};

void sortNodeDouble(DLL *L){
    if (L->first == nullptr){
        return;
    };

    if (L->first->Next == nullptr){
        cout << "Data Cuma ada 1" << endl;
        return;
    };

    NodeDouble *Sorted = nullptr;

    while (L->first != nullptr){
        NodeDouble *max = L->first;
        NodeDouble *Temp = L->first->Next;

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

void cetakNodeDouble(DLL *L){
    if (L->first == nullptr){
        cout << "Data Kosong" << endl;
        return;
    };
    int counter = 0;

    NodeDouble *Temp = L->first;
    while(Temp != nullptr){
        counter = counter + 1;
        cout << counter << ". " 
        << Temp->nim << " " 
        <<Temp->name << " " 
        << Temp->jurusan << " "
        << Temp->ipk << endl;
        Temp = Temp->Next;
    };
    cout << "NULL" << endl;
};

void saveToFileDouble(DLL *L, string writeFile){
    ofstream file (writeFile);

    if (L->first == nullptr){
        cout << "Data Kosong" << endl;
        return;
    };

    if (!file.is_open()){
        cout << "File Kosong" << endl;
        return;
    };

    NodeDouble *Temp = L->first;
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
