#include <stdbool.h>
#include <iostream>
#include <string>
#include "func.h"


void DestroyStack(Stack *Data){
    int i;
    for (i = 0; i <= max; i++){
        Data->namaBuku[i] = "_";
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

void push (Stack *Data, string namaBuku){

    if (isEmptyStack(Data)){
        Data->top = 1;
        Data->namaBuku[Data->top] = namaBuku;
        return;
    };

    if (isFullStack(Data)){
        return;
    };

    Data->top = Data->top + 1;
    Data->namaBuku[Data->top] = namaBuku;

    return;
};

void pop (Stack *Data, string *rollbackBuku){
    if (isEmptyStack(Data)){
        return;
    };

    if (rollbackBuku != nullptr){
        *rollbackBuku = Data->namaBuku[Data->top];
    };

    Data->namaBuku[Data->top] = "_";
    Data->top = Data->top - 1;

    return;
};

void cetakStack(Stack *Data){
    if (isEmptyStack(Data)){
        return;
    };
    int i, counter = 0;

    for (i = Data->top; i >= 1; i--){
        counter = counter + 1;

        if (counter == 1){
            cout << endl << counter << ". " << Data->namaBuku[i] << "   Top" << endl;
        } else {
            cout << counter << ". " << Data->namaBuku[i] << endl;
        };

    };

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

    cout <<  endl <<"Nama Buku Posisi ke " << position + 1 << ": " << Data->namaBuku[idx] << endl;
};

void changeStack(Stack *Data, int position, string namaBuku){
    if (isEmptyStack(Data)){
        return;
    };

    if (!( (position >= 1) && (position <= Data->top) )){
        return;
    };

    position = position - 1;
    int idx = Data->top - position;

    string VeryTemp = Data->namaBuku[idx];
    Data->namaBuku[idx] = namaBuku;

    cout << endl << "Buku Posisi ke " << position + 1 << ": " << VeryTemp << " Menjadi " << Data->namaBuku[idx] << endl;
};
