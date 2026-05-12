#include <stdbool.h>
#include <iostream>
#include "func.h"

Stack* initStack(){
    Stack *New = new Stack;
    New->top = nullptr;
    return New;
};

Node *addNode(int data){
    Node *New = new Node;
    New->data = data;
    New->Next = nullptr;
    New->Prev = nullptr;
    return New;
};

bool isEmptyStack(Stack *Data){
    return (Data->top == nullptr);
};

void push (Stack *Data, int data){
    Node *New = addNode(data);

    if (isEmptyStack(Data)){
        Data->top = New;
        return;
    };

    New->Next = Data->top;
    Data->top->Prev = New;
    Data->top = New;
    
    return;
};

void pop (Stack *Data, int *rollback){
    if (isEmptyStack(Data)){
        return;
    };

    Node *Temp = Data->top;
    Data->top = Data->top->Next;
    *rollback = Temp->data;
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

    Node *Temp = Data->top;
    while(Temp->Next != nullptr){
        cout << Temp->data << " <-> ";
        Temp = Temp->Next;
    };
    cout << Temp->data << "-> nullptr" << endl;
};