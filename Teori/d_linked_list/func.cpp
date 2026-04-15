#include <stdio.h>
#include <stdlib.h>
#include "func.h"

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

int sizeListNode(DLL *L){
    int counter = 0;

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

void cariNode(DLL *L, int target){
    if (L->first == nullptr){
        return;
    };

    int counter = 1;

    Node *Temp = L->first;
    while(Temp != nullptr){
        if (Temp->data == target){
            printf("Ada di Node : %d\n", counter);
            return;
        };
        counter = counter + 1;
        Temp = Temp->Next;
    };

    printf("Tidak ada data : %d didalam node!\n", target);
};

void reverseList(DLL *L) {
    if (L->first == NULL) {
        return;
    }

    Node *Curr = L->first;
    Node *Temp = NULL;

    while (Curr != NULL) {
        Temp = Curr->Prev;
        Curr->Prev = Curr->Next;
        Curr->Next = Temp;

        Curr = Curr->Prev;
    }

    if (Temp != NULL) {
        L->first = Temp->Prev;
    }
};

void updateNode(DLL *L, int data, int position) {
    if (L->first == NULL) {
        return;
    };

    Node *Temp = L->first;
    int counter = 1;

    while (Temp != NULL) {
        if (counter == position) {
            Temp->data = data;
            return;
        };
        counter = counter + 1;
        Temp = Temp->Next;
    };
    printf("Posisi tidak Sesuai %d\n", position);
};  
