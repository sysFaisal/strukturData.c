#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include "func.h"
#include "fstream"

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

int bacafile(string file){
    ifstream myfile (file);

    if (!myfile.is_open()){
        return -1;
    };
};

void insertFirstNode(SLL *L, int data){
    if (L == NULL){
        L = initNode();
    };

    Node *New = addNode(data);

    if (L->first == NULL){
        L->first = New;
        return;
    };

    New->Next = L->first;
    L->first = New;
};

int sizeListNode(SLL *L){
    int counter = 0;
    if (L == NULL){
        return counter;
    };

    if (L->first == nullptr){
        return counter;
    };

    Node *Temp = L->first;
    while (Temp->Next != nullptr){
        counter = counter + 1;
        Temp = Temp->Next;
    };
    counter = counter + 1;

    return counter;
};

/*
void cetakNode(SLL *L){
    Node *Temp = L->first;
    while(Temp->Next != nullptr){
        printf("%d -> ", Temp->data);
        Temp = Temp->Next;
    };
    printf("%d -> ", Temp->data);
};
*/