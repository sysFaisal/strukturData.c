#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Node{
    int data;
    struct Node *Next;
};

struct SLL{
    struct Node *first;
};

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

    Node *Temp = L->first;
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

int main(){

    SLL *L = initNode();
    insertLastNode(L, 1);
    insertFirstNode(L, 2);
    insertFirstNode(L, 3);
    insertFirstNode(L, 4);
    insertFirstNode(L, 5);
    insertFirstNode(L, 6);

    if (cariNode(L,7)){
        printf("Ada di Node : %d\n", cariNode(L,4));
    };
    printf("Size List : %d\n", sizeListNode(L));


    getchar();
    getchar();
};


/*
typedef struct Node {
    int data;
    struct Node *next;

    void init(){
        this->data = NULL;
        this->next = nullptr;
    };

    void InsertLastNode(int data1){
        Node *Temp = this->next;
        Node *New = new Node;

        New->init();
        New->data = data1;
        New->next = NULL;

        while (Temp->next != NULL){
            Temp = Temp->next;
        };
        Temp->next = New;
    };

} Node;

Node* delete (Node *Temp){

};
typedef struct {
    struct Node *first;
}First;



int main(){
    Node *Head = new Node;

    Head->init();
    Head->InsertLastNode(1);
    Head->InsertLastNode(20);    
     /*
    CreateList(); Menciptakan First
    AddFirst(); Menambahkan Element di awal
    Addlast
    CreateElementList();  menciptajan element list baru
    SizeList(); Menghitung jumlah Element dalam list
    CreateElementList();   menghapus salah satu element
    */
