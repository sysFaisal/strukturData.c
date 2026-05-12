#ifndef _Func_H
#define _Func_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>
#include <stdbool.h>

using namespace std;
#define max 5

struct Queue{
    int data[max + 1];
    int front;
    int rear;
};

void ClearQueue(Queue *Data);
Queue initQueue();
bool isEmptyQueue(Queue *Data);
bool isFullQueue(Queue *Data);
int CountQueue(Queue *Data);
void enqueue(Queue *Data, int data);
void dequeue(Queue *Data, int *rollback = nullptr);
void cetakQueue(Queue *Data);

#endif