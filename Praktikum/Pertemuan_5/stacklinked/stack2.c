/* Program : stack2.h
Author : 2550081098, Faisal Fajari
Kelas : E
Deskripsi: Body file dari prototype stack linked list
Tanggal : 21/04/2026
*/
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "stack2.h"

void CreateStack(Stack *S){
    S->TOP = nil;
    S->BUTTOM = nil;
};

address Alokasi(infotype x){
    address New = malloc(sizeof(ElmStack));
    if (New == nil){
        return nil;
    };
    New->Info = x;
    New->next = nil;
    return New;
};

boolean IsStackEmpty(Stack S) {
    return (S.BUTTOM == nil);
};

boolean CariElemenStack(Stack S, infotype x){
    if(IsStackEmpty(S)){
        return false;
    };

    address Temp = S.TOP;
    while (Temp != nil){
        if (Temp->Info == x){
            return true;
        };
        Temp = Temp->next;
    };
    
    return false;
};

void DeAlokasi(address P){
    free(P);
    P = nil;
};

void Push (Stack *S, infotype X){
    address New = Alokasi(X);

    if (New == nil){
        return;
    };

    if (IsStackEmpty((*S))){
        S->TOP = New;
        S->BUTTOM = New;
        return;
    };

    S->TOP->next = New;
    S->TOP = New;

    return;
};

void Pop (Stack *S, infotype *X){
    if (IsStackEmpty((*S))){
        return;
    };

    address Temp = S->TOP;
    *X = Temp->Info;

    if (S->TOP == S->BUTTOM){
        S->BUTTOM = nil;
        S->TOP = nil;
        DeAlokasi(Temp);
        return;
    };

    address Prev1 = NULL;
    address Prev = S->BUTTOM;

    while (Prev->next != NULL){
        Prev1 = Prev;
        Prev = Prev->next;
    };

    S->TOP = Prev1;
    S->TOP->next = nil;

    DeAlokasi(Temp);

};

void CetakStack(Stack S) {

    if (IsStackEmpty(S)){
        printf("Element Kosong\n");
        return;
    };

    int flag = 0;
    address Temp = S.BUTTOM;

    while(Temp != nil){

        if (flag == 0){
            printf("%d ", Temp->Info);
            flag = flag + 1;
        } else {
            printf("-> %d ", Temp->Info);
        };
        Temp = Temp->next;
    };

    printf("-> TOP & NULL");
};

