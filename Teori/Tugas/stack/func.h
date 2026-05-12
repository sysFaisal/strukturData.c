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
    struct Node *Prev;
};

struct Stack{
    struct Node *top;
};

Stack* initStack();
Node *addNode(int data);
bool isEmptyStack(Stack *Data);
void push (Stack *Data, int data);
void pop (Stack *Data, int *rollback = nullptr);
void cetakStack(Stack *Data);

#endif