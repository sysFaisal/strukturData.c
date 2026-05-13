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
    string namaBuku;
    struct Node *Next;
    struct Node *Prev;
};

struct Stack{
    struct Node *top;
};

Stack* initStack();
Node *addNode(int nim, string namaBuku);
bool isEmptyStack(Stack *Data);
void push (Stack *Data, string namaBuku);
void pop (Stack *Data, string *rollbackBuku = nullptr);
void cetakStack(Stack *Data);

#endif
