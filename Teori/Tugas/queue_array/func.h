#ifndef _Func_H
#define _Func_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>
#include <stdbool.h>

using namespace std;
#define max 2

struct File{
    string namaFile;
    float sizeMB;
};

struct Queue{
    File file[max + 1];
    int front;
    int rear;
};

void ClearQueue(Queue *Data);
Queue initQueue();
bool isEmptyQueue(Queue *Data);
bool isFullQueue(Queue *Data);
int CountQueue(Queue *Data);
void enqueue(Queue *Data, float sizeMB, string namaFile);
void dequeue(Queue *Data, float *rollbackSizeMB = nullptr, string *rollbackNamaFile = nullptr);
void cetakQueue(Queue *Data);

#endif
