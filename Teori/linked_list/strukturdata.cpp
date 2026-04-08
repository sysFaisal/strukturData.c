#include <iostream>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    struct Node *Next;
};

struct SLL{
    struct Node *first;
};

SLL* initNode(){
    return new SLL;
};

Node *addNode(int dat){
    Node *New = new Node;
    New->data = dat;
    New->Next = nullptr;
    return New;
};

void insertLastNode(SLL *L){
    
};



int main(){

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
