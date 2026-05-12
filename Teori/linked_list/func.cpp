#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

SLL* initNode(){
    SLL *L = new SLL;
    L->first = nullptr;
    return L;
};

Node *addNode(int dat){
    Node *New = new Node;
    New->data = dat;
    New->Next = nullptr;
    return New;
};

void insertLastNode(SLL *L, int data){
    if (L == NULL){
        L = initNode();
    };

    Node *New = addNode(data);

    if (L->first == NULL){
        L->first = New;
        return;
    };

    Node *Temp = L->first;

    while(Temp->Next != nullptr){
        Temp = Temp->Next;
    };

    Temp->Next = New;
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

void deletefirstNode(SLL *L){
    if (L == NULL){
        return;
    };

    if (L->first == nullptr){
        return;
    };

    Node *Temp = L->first;
    L->first = Temp->Next;
    free(Temp);
    Temp = NULL;
};

void deleteLastNode(SLL *L){
    if (L == NULL){
        return;
    };

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
    free(Temp);
    Temp = NULL;
};

int cariNode(SLL *L, int target){
    int counter = 0;
    Node *Temp = L->first;

    while (Temp->Next != nullptr){
        counter = counter + 1;
        if (Temp->data == target){
            return counter;
        };
        Temp = Temp->Next;
    };

    counter = counter + 1;
    if (Temp->data == target){
        return counter;
    };

    return 0;

};

void cetakNode(SLL *L){
    Node *Temp = L->first;
    while(Temp->Next != nullptr){
        printf("%d -> ", Temp->data);
        Temp = Temp->Next;
    };
    printf("%d -> ", Temp->data);
};