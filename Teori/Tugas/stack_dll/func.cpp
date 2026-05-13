#include <stdbool.h>
#include <iostream>
#include "func.h"

Stack* initStack(){
    Stack *New = new Stack;
    New->top = nullptr;
    return New;
};

Node *addNode(string namaBuku){
    Node *New = new Node;
    New->namaBuku = namaBuku;
    New->Next = nullptr;
    New->Prev = nullptr;
    return New;
};

bool isEmptyStack(Stack *Data){
    return (Data->top == nullptr);
};

void push (Stack *Data, string namaBuku){
    Node *New = addNode(namaBuku);

    if (isEmptyStack(Data)){
        Data->top = New;
        return;
    };

    New->Next = Data->top;
    Data->top->Prev = New;
    Data->top = New;

    return;
};

void pop (Stack *Data, string *rollbackBuku){
    if (isEmptyStack(Data)){
        return;
    };

    Node *Temp = Data->top;
    Data->top = Data->top->Next;

    if(rollbackBuku != nullptr){
        *rollbackBuku = Temp->namaBuku;
    };

    delete Temp;

    if (!isEmptyStack(Data)){
        Data->top->Prev = nullptr;
    };

    return;
};

void cetakStack(Stack *Data){
    if (isEmptyStack(Data)){
        return;
    };
    int counter = 0;
    Node *Temp = Data->top;
    cout << endl;

    while(Temp != nullptr){
        counter = counter + 1;

        if (counter == 1){
            cout << counter << ". " << Temp->namaBuku << "  " << "Top" << endl;
        } else {
            cout << counter << ". " << Temp->namaBuku << endl;
        };

        Temp = Temp->Next;
    };
};
