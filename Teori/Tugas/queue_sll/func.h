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
    string namafile;
    float sizeMB;
    struct Node *Next;
};

struct Queue{
    struct Node *rear;
    struct Node *front;
};

Queue* initQueue();
Node *addNode(float sizeMB, string namaFile);
bool isEmptyQueue(Queue *Data);
void enqueue(Queue *Data, float sizeMB, string namaFile);
void dequeue(Queue *Data, float *rlback_ksizeMB = nullptr, string *rlback_namafile = nullptr);
void cetakQueue(Queue *Data);

#endif
