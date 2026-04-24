#ifndef _Func_H
#define _Func_H
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include "fstream"

using namespace std;

struct Node{
    int nim;
    string name;
    string Jurusan;
    float ipk; 
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