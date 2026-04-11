#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Node{
    int data;
    struct Node *Next;
    struct Node *Prev;
};

struct DLL{
    struct Node *first;
};

DLL* initDLL(){
    DLL *New = new DLL;
    New->first = NULL;
    return New;
};

Node* addNode(int data){
    Node *New = new Node;
    New->data = data;
    New->Next = nullptr;
    New->Prev = nullptr;
    return New;
};

void insertLastNode(DLL *L, int data){

    if (L == NULL){
        L = initDLL();
    };

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

void insertFirstNode(DLL *L, int data){

    if (L == NULL){
        L = initDLL();
    };

    Node *New = addNode(data);

    if (L->first == NULL){
        L->first = New;
        return;
    };
    Node *Temp = L->first;
    Temp->Prev = New; 
    New->Next = Temp;
    L->first = New;

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
    printf("%d -> \n", Temp->data);

};

void cetakPrevNode(DLL *L){

    if (L->first == NULL){
        return;
    };
    
    Node *Temp = L->first;
    while(Temp->Next != NULL){
        Temp = Temp->Next;
    };

    while(Temp->Prev != NULL){
        printf(" <- %d", Temp->data);
        Temp = Temp->Prev;
    };
    printf(" <- %d\n", Temp->data);

};

int sizeListNode(DLL *L){
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

void deleteLastNode(DLL *L){
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
    Temp->Prev = nullptr;
    free(Temp);
    Temp = NULL;
    
};
void deleteFirstNode(DLL *L){
    if (L == NULL){
        return;
    };

    if (L->first == nullptr){
        return;
    };

    Node *Temp = L->first;
    Node *Temp1 = nullptr;

    Temp1->Next = Temp->Next;
    Temp->Next->Prev = nullptr;
    free(Temp);
    Temp = NULL;
};

int main(){
    DLL *L = initDLL();
    insertLastNode(L, 2);
    insertLastNode(L, 3);
    insertFirstNode(L, 1);
    insertFirstNode(L, 0);
    insertLastNode(L, 4);
    deleteLastNode(L);
    cetakNextNode(L);
    cetakPrevNode(L);
    printf("Size List : %d\n", sizeListNode(L));

    getchar();
    getchar();
};