#ifndef _Func_H
#define _Func_H
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *Next;
};

struct SLL{
    struct Node *first;
};

SLL* initNode();
Node *addNode(int dat);
void insertLastNode(SLL *L, int data);
void insertFirstNode(SLL *L, int data);
int sizeListNode(SLL *L);
void deleteLastNode(SLL *L);
int cariNode(SLL *L, int target);
void cetakNode(SLL *L);

#endif