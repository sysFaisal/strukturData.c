/* Program : stack.c
Author : 2550081098, Faisal Fajari
Kelas : E
Deskripsi: Body file dari prototype stack
Tanggal : 
*/
#include <stdio.h>
#include "boolean.h"
#include "stack.h"

void CreateStack(Stack *S){
    S->TOP = Nil;
};

boolean IsStackEmpty (Stack S){
    return (S.TOP == Nil);
};

boolean IsStackFull(Stack S){
    return (S.TOP == MaxEl);
};

void Push (Stack *S, infotype X){
    Stack Temp = *S;

    if (IsStackFull(Temp)){
        return;
    };

    S->TOP = S->TOP + 1;
    S->T[S->TOP] = X;
};

void Pop (Stack *S, infotype *X){
    Stack Temp = *S;
    if (IsStackEmpty(Temp)){
        printf("Element Kosong\n");
        return;
    };

    *X = S->T[S->TOP]; 
    S->T[S->TOP] = Nil;
    S->TOP = S->TOP - 1;
};

void PrintStackInfo (Stack S){
    if (IsStackEmpty(S)){
        printf("Element Kosong\n");
        return;
    };

    int i;

    for (i = 1; i <= S.TOP; i++){
        printf("%d", S.T[i]);

        if (i < S.TOP){
            printf(", ");
        };
    };

    printf(" < - TOP");
};

boolean isInfoKetemu(Stack S, infotype x){
    if (IsStackEmpty(S)){
        printf("Element Kosong\n");
        return false;
    };

    int i;

    for (i = 1; i <= S.TOP; i++){
        if (S.T[i] == x){
            return true;
        }
    }

    return false;
};

address CariElemenStack(Stack S, infotype x){
    if (IsStackEmpty(S)){
        printf("Element Kosong\n");
        return IdxUndef;
    };

    int i;

    for (i = 1; i <= S.TOP; i++){
        if (S.T[i] == x){
            return i;
        }
    }

    return IdxUndef;
    
};