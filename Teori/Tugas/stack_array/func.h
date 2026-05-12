#ifndef _Func_H
#define _Func_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>
#include <stdbool.h>

using namespace std;
#define max 50

struct Stack{
    int data[max + 1];
    int top;
};

void DestroyStack(Stack *Data);
Stack initStack();
bool isEmptyStack(Stack *Data);
bool isFullStack(Stack *Data);
int CountStack(Stack *Data);
void push (Stack *Data, int data);
void pop (Stack *Data, int *rollback = nullptr);
void cetakStack(Stack *Data);
void peekStack(Stack *Data, int position);
void changeStack(Stack *Data, int position, int data);

#endif