#include <iostream>
#include <stdlib.h>
#include "func.h"
#include <stdbool.h>


void ClearQueue(Queue *Data){
    int i;
    for (i = 0; i <= max; i++){
        Data->file[i].namaFile = "_";
        Data->file[i].sizeMB = 0;
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

File addNode(float sizeMB, string namaFile){
    File New;
    New.namaFile = namaFile;
    New.sizeMB = sizeMB;
    return New;
};

void enqueue(Queue *Data, float sizeMB, string namaFile){

    if(isEmptyQueue(Data)){
        Data->front = 1;
        Data->rear = 1;
        Data->file[Data->rear] = addNode(sizeMB, namaFile);
        return;
    };

    if (!isFullQueue(Data)){
        Data->rear = Data->rear + 1;
        Data->file[Data->rear] = addNode(sizeMB, namaFile);
        return;
    };

    printf("Data Penuh");

};

void dequeue(Queue *Data, float *rollbackSizeMB, string *rollbackNamaFile){
    if (isEmptyQueue(Data)){
        return;
    };

    int i;

    if (rollbackNamaFile != nullptr){
        *rollbackNamaFile = Data->file[Data->front].namaFile;
    }

    if (rollbackSizeMB != nullptr){
        *rollbackSizeMB = Data->file[Data->front].sizeMB;
    };

    for (i = 1; i <= Data->rear; i++){
        if (i == Data->rear){
            Data->file[Data->rear] = addNode(0, "_");
            break;
        };
        Data->file[i] = Data->file[i + 1];
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
    int counter = 0;

    for (i = 1; i <= Data->rear; i++){
        counter = counter + 1;

        if (counter == 1){
            cout << endl << counter << ". " << Data->file[i].namaFile << "   " << Data->file[i].sizeMB << " MB" << "   Front" << endl;
        } else {
            cout << counter << ". " << Data->file[i].namaFile << "   " << Data->file[i].sizeMB << " MB" << endl;
        };

    };

    return;
};
