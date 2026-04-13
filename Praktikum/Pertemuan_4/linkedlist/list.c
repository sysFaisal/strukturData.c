/* Program : list.c
Author : 2550081098, Faisal Fajari
Kelas : E
Deskripsi: Body dari prototype Linked List
Tanggal : 13/04/2026
*/

#include "list.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

void CreateList (List *L){
    L->First = NULL;
};

address Alokasi (infotype X){
    address P;
    P = malloc(sizeof(ElmtList));
    if (P == NULL){
        return NULL;
    };
    P->info = X;
    P->next = NULL;
    return P;
};

void DeAlokasi (address P){
    free(P);
    P = NULL;  
};

boolean ListEmpty(List L){
    return (L.First == NULL);
};

void InsFirst (List *L, infotype X){

    address Temp = Alokasi(X);

    if (L->First == NULL){
        L->First = Temp;
        return;
    };
    
    Temp->next = L->First;
    L->First = Temp;

};

void InsLast (List * L, infotype X){

    address Curr = L->First;
    address New = Alokasi(X);

    if (New == NULL){
        return;
    };

    if (L->First == NULL){
        L->First = New; 
        return;
    };

    while (Curr->next != NULL){
        Curr = Curr->next;
    };

    Curr->next = New;

};

void InsAfter (List * L, infotype X, infotype Y){

    address Curr = L->First;
    address New = Alokasi(X);
    address Temp = NULL;

    if (New == NULL){
        return;
    };

    if (L->First == NULL){
        L->First = New;
        return;
    };
    
    while (Curr != NULL){

        if (Curr->info == Y){
            Temp = Curr->next;
            Curr->next = New;
            New->next = Temp;
            return;
        };
        Curr = Curr->next;
    };

    printf("Error! Y Tidak ditemukan");

};

void DelFirst (List * L, infotype *X){

    address Curr = L->First;

    if (Curr == NULL){
        return;
    };

    *X = Curr->info;
    L->First = Curr->next;
    DeAlokasi(Curr);

};

void DelLast (List *L, infotype *X){

    address Curr = L->First;

    if (L->First == NULL){
        return;
    };

    address Prev = NULL;

    if (Curr->next == NULL){
        DelFirst(L, X);
        return;
    };

    while (Curr->next != NULL){
        Prev = Curr;
        Curr = Curr->next;
    };

    *X = Curr->info;
    Prev->next = NULL;
    DeAlokasi(Curr);
};

void DelAfter (List * L, infotype *X, infotype Y){

    address Curr = L->First;

    if (Curr == NULL){
        return;
    };

    while (Curr != NULL && Curr->next != NULL){
        if (Curr->info == Y){
            address Del = Curr->next;
            *X = Del->info;

            Curr->next = Del->next;
            DeAlokasi(Del);
            return;
        };
        Curr = Curr->next;
    };

    printf("Error!");
};

void PrintInfo (List L){
    if (L.First == NULL){
        printf("List Kosong");
        return;
    }; 

    address Temp = L.First;

    while (Temp != NULL){
        printf("%d -> ", Temp->info);
        Temp = Temp->next;
    };

    printf("NULL\n");
};

int NbElmt (List L){

    if (L.First == NULL){
        return 0;
    };

    address Temp = L.First;
    int counter = 0;

    while (Temp != NULL){
        counter = counter + 1;
        Temp = Temp->next;
    };

    return counter;
};

address Search (List L, infotype X){
    if (L.First == NULL){
        return NULL;
    };

    address Temp = L.First;

    while (Temp != NULL){
        if (Temp->info == X){
            return Temp;
        };
        Temp = Temp->next;
    };

    return NULL;
};

void InversList (List *L){

    if (L->First == NULL){
        return;
    };

    address Curr = L->First;
    address Next = NULL;
    address Temp = NULL;

    while (Curr != NULL){
        Next = Curr->next;
        Curr->next = Temp;
        Temp = Curr;
        Curr = Next;
    };

    L->First = Temp;

};

List getNewInversList (List L){
    List New;
    CreateList(&New);
    address Temp = L.First;

    if (Temp == NULL){
        return New;
    };

    while (Temp != NULL){
        InsLast(&New, Temp->info);
        Temp = Temp->next;
    };

    InversList(&New);
    return New;
};