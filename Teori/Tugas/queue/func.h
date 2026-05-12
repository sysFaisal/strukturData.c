#ifndef _Func_H
#define _Func_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>
#include <stdbool.h>

using namespace std;

struct Node{
    int data;
    struct Node *Next;
};

struct Queue{
    struct Node *rear;
    struct Node *front;
};

Queue* initQueue();
Node *addNode(int data);
bool isEmptyQueue(Queue *Data);
void enqueue(Queue *Data, int data);
void dequeue(Queue *Data, int *rollback = nullptr);
void cetakQueue(Queue *Data);

#endif