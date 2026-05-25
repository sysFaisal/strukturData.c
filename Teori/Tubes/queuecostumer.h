#ifndef _QueueCostumer_H
#define _QueueCostumer_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

struct QueueCos{
    string nama;
    string noHP;
    string kodePulsa;
    int jumlah;
    QueueCos *next;
};

struct Costumer{
    QueueCos *front;
    QueueCos *rear;
    int counter;
};

inline Costumer createQueue(){
    Costumer New;
    New.front = nullptr;
    New.rear = nullptr;
    return New;
};

inline QueueCos* alokasiQueue(string nama, string noHp, string kodePulsa, int jumlah){
    QueueCos *New = new QueueCos;
    New->nama = nama;
    New->noHP = noHp;
    New->kodePulsa = kodePulsa;
    New->jumlah = jumlah;
    return New;
};

inline bool isEmptyQueue(Costumer L){
    return (L.front == nullptr);
};

inline void enqueue(Costumer *L, string nama, string noHp, string kodePulsa, int jumlah){

    QueueCos *New = alokasiQueue(nama, noHp, kodePulsa, jumlah);
    if (isEmptyQueue(*(L))){
        L->front = New;
        L->rear = New;
        return;
    };

    L->rear->next = New;
    L->rear = New;
};

inline void dequeue(Costumer *L, string *nama, string *noHp, string *kodePulsa, int *jumlah){

    if (isEmptyQueue(*(L))){
        return;
    };

    QueueCos *Temp = L->front;
    *nama = Temp->nama;
    *noHp = Temp->noHP;
    *kodePulsa = Temp->kodePulsa;
    *jumlah = Temp->jumlah;
    
    if (L->front->next == nullptr){
        L->front = nullptr;
        L->rear = nullptr;
        free (Temp);
        return;
    };

    L->front = L->front->next;
    free (Temp);
};

#endif