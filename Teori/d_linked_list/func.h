#ifndef _Func_H
#define _Func_H
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *Next;
    struct Node *Prev;
};

struct DLL{
    struct Node *first;
};

DLL* initDLL();

Node* addNode(int data);

void insertLastNode(DLL *L, int data);

void insertFirstNode(DLL *L, int data);

void insertTargetNode(DLL *L, int data, int position);

void cetakNextNode(DLL *L);

void cetakPrevNode(DLL *L);

int sizeListNode(DLL *L);

void deleteLastNode(DLL *L);

void deleteFirstNode(DLL *L);

void deleteTargetNode(DLL *L, int target);

void cariNode(DLL *L, int target);

void reverseList(DLL *L);

void updateNode(DLL *L, int data, int position);

#endif