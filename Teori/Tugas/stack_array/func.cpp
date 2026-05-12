#include <stdbool.h>
#include <iostream>
#include "func.h"


void DestroyStack(Stack *Data){
    int i;
    for (i = 0; i <= max; i++){
        Data->data[i] = 0;
    };
    Data->top = 0;
    return;
};

Stack initStack(){
    Stack New;
    DestroyStack(&New);
    return New;
};

bool isEmptyStack(Stack *Data){
    return (Data->top == 0);
};

bool isFullStack(Stack *Data){
    return (Data->top == max);
};

int CountStack(Stack *Data){
    return Data->top;
};

void push (Stack *Data, int data){

    if (isEmptyStack(Data)){
        Data->top = 1;
        Data->data[Data->top] = data;
        return;
    };

    if (isFullStack(Data)){
        return;
    };

    Data->top = Data->top + 1;
    Data->data[Data->top] = data;
    
    return;
};

void pop (Stack *Data, int *rollback){
    if (isEmptyStack(Data)){
        return;
    };

    *rollback = Data->data[Data->top];
    Data->data[Data->top] = 0;
    Data->top = Data->top - 1;

    return;
};

void cetakStack(Stack *Data){
    if (isEmptyStack(Data)){
        return;
    };
    int i;

    for (i = Data->top; i >= 1; i--){
        if (i == 1){
            cout << Data->data[i];
            break;  
        };
        cout << Data->data[i] << " -> ";
    };

    cout << endl;

    return;
};

void peekStack(Stack *Data, int position){
    if (isEmptyStack(Data)){
        return;
    };

    if (!( (position >= 1) && (position <= Data->top) )){
        return;
    };

    position = position - 1;
    int idx = Data->top - position;

    cout << "Posisi ke " << position + 1 << ": " << Data->data[idx] << endl;  
};

void changeStack(Stack *Data, int position, int data){
    if (isEmptyStack(Data)){
        return;
    };

    if (!( (position >= 1) && (position <= Data->top) )){
        return;
    };  

    position = position - 1;
    int idx = Data->top - position;

    int VeryTemp = Data->data[idx]; 
    Data->data[idx] = data;

    cout << "Data Posisi ke " << position + 1 << ": " << VeryTemp << " Menjadi " << Data->data[idx] << endl;  
};