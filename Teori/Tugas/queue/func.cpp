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

Node *addNode(int data){
    Node *New = new Node;
    New->data = data;
    New->Next = nullptr;
    return New;
};

bool isEmptyQueue(Queue *Data){
    return (Data->front == nullptr);
};

void enqueue(Queue *Data, int data){
    Node *New = addNode(data);

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

void dequeue(Queue *Data, int *rollback){
    if (isEmptyQueue(Data)){
        return;
    };

    Node *Temp = Data->front;
    Data->front = Temp->Next;

    if (rollback != nullptr){
        *rollback = Temp->data;
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

    Node *Temp = Data->front;
    while(Temp->Next != nullptr){
        cout << Temp->data << " -> ";
        Temp = Temp->Next;
    };
    cout << Temp->data << "-> nullptr" << endl;

    return;
};
