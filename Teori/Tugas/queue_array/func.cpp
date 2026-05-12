#include <iostream>
#include <stdlib.h>
#include "func.h"
#include <stdbool.h>


void ClearQueue(Queue *Data){
    int i;
    for (i = 0; i <= max; i++){
        Data->data[i] = 0;
    };
    Data->front = 0;
    Data->rear = 0;
    return;
};

Queue initQueue(){
    Queue New;
    ClearQueue(&New);
    return New;
};

bool isEmptyQueue(Queue *Data){
    return (Data->rear == 0);
};

bool isFullQueue(Queue *Data){
    return (Data->rear == max);
};

int CountQueue(Queue *Data){
    return Data->rear;
};

void enqueue(Queue *Data, int data){

    if(isEmptyQueue(Data)){
        Data->front = 1;
        Data->rear = 1;
        Data->data[Data->rear] = data;
        return;
    };

    if (!isFullQueue(Data)){
        Data->rear = Data->rear + 1;
        Data->data[Data->rear] = data;
        return;
    };

    printf("Data Penuh");

};

void dequeue(Queue *Data, int *rollback){
    if (isEmptyQueue(Data)){
        return;
    };

    int i;
    *rollback = Data->data[Data->front];

    for (i = 1; i <= Data->rear; i++){
        if (i == Data->rear){
            Data->data[Data->rear] = 0;
            break;
        };
        Data->data[i] = Data->data[i + 1];
    };

    Data->rear = Data->rear - 1;
    if (Data->rear == 0){
        Data->front = 0;
    };

    return;
};

void cetakQueue(Queue *Data){
    if (isEmptyQueue(Data)){
        return;
    };
    int i;

    for (i = 1; i <= Data->rear; i++){
        if (i == Data->rear){
            cout << Data->data[i];
            break;  
        };
        cout << Data->data[i] << " <- ";
    };

    cout << endl;

    return;
};
