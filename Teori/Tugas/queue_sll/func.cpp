#include <iostream>
#include <stdlib.h>
#include "func.h"
#include <stdbool.h>

Queue* initQueue(){
    Queue *New = new Queue;
    New->front = nullptr; //top
    New->rear = nullptr; //bottom
    return New;
};

Node *addNode(float sizeMB, string namaFile){
    Node *New = new Node;
    New->sizeMB = sizeMB;
    New->namafile = namaFile;
    New->Next = nullptr;
    return New;
};

bool isEmptyQueue(Queue *Data){
    return (Data->front == nullptr);
};

void enqueue(Queue *Data, float sizeMB, string namaFile){
    Node *New = addNode(sizeMB, namaFile);

    if (Data->front == nullptr){
        Data->front = New;
        Data->rear = New;
        return;
    };

    Node *Temp = Data->rear;
    Temp->Next = New;
    Data->rear = New;

    return;
};

void dequeue(Queue *Data, float *rlback_ksizeMB, string *rlback_namafile){
    if (isEmptyQueue(Data)){
        return;
    };

    Node *Temp = Data->front;
    Data->front = Temp->Next;

    if (rlback_ksizeMB != nullptr){
        *rlback_ksizeMB = Temp->sizeMB;
    };

    if (rlback_namafile != nullptr){
        *rlback_namafile = Temp->namafile;
    };

    delete Temp;

    if (Data->front == nullptr){
        Data->rear = nullptr;
    };

    return;
};

void cetakQueue(Queue *Data){
    if (isEmptyQueue(Data)){
        return;
    };

    cout << endl;
    int counter = 0;
    Node *Temp = Data->front;
    while(Temp != nullptr){
        counter = counter + 1;
        if (counter == 1){
            cout << counter << ". " << Temp->namafile << "  " << Temp->sizeMB << "MB" << "  " << "Front" << endl;
        } else {
            cout << counter << ". " << Temp->namafile << "  " << Temp->sizeMB << "MB" << endl;
        };
        
        Temp = Temp->Next;
    };

    return;
};
