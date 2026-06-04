/* Program : doubleLinkList.h
Author : 2550081098, Faisal Fajari
Kelas : E
Deskripsi: Body file dari prototype double linked list
Tanggal : 26/5/2026
*/
/* ADT double Linear Linked List
pembentukan tipe List Linier dan operasi bagi List
Representasi fisik List dengan pointer
*/


#include <stdlib.h>
#include "boolean.h"
#include "doubleLinkList.h"
#include <stdio.h>

boolean ListEmpty(List L){
    return (L.First == nullptr);
};

void CreateList(List *L){
    L->First = nullptr;
};

address Alokasi(infotype X){
    address New = malloc(sizeof(ElmtList));
    New->info = X;
    New->next = nullptr;
    New->prev = nullptr;
    return New;
};

void Dealokasi(address P){
    free (P);
};

address Search(List L, infotype X){
    if (ListEmpty(L)){
        return nullptr;
    };

    address Temp = L.First;
    while (Temp != nullptr){
        if (Temp->info == X){
            return Temp;
        };
        Temp = Temp->next;
    };

    return nullptr;
};

void AddInElm(List *L, infotype X, infotype Y){
    if (ListEmpty(*(L))){
        return;
    };

    address Temp = Search(*(L), Y);
    if (Temp == nullptr){
        return;
    };

    address New = Alokasi(X);
    if (Temp->next != nullptr){
        address Next = Temp->next;
        New->prev = Temp;
        New->next = Next;
        Next->prev = New;
        Temp->next = New;
        return;
    };

    New->prev = Temp;
    Temp->next = New;

};

void AddFirst(List *L, infotype X){
    address New = Alokasi(X);
    if (ListEmpty(*(L))){
        L->First = New;
        return;
    };

    New->next = L->First;
    L->First->prev = New;
    L->First = New;

};

void AddLast(List *L, infotype X){
    if (ListEmpty(*(L))){
        AddFirst(L, X);
        return;
    };

    address New = Alokasi(X);
    address Temp = L->First;

    while (Temp->next != nullptr){
        Temp = Temp->next;
    };

    New->prev = Temp;
    Temp->next = New;

};

void DelFirst(List *L, infotype *X){
    if (ListEmpty(*(L))){
        return;
    };

    if (L->First->next == nullptr){
        address Temp = L->First;
        L->First = nullptr;
        *X = Temp->info;
        Dealokasi(Temp);
        return;
    };

    address Next = L->First->next;
    address Temp = L->First;

    L->First = Next;
    L->First->prev = nullptr;

    *X = Temp->info;
    Dealokasi(Temp);
};

void DelLast(List *L, infotype *X){
    if (ListEmpty(*(L))){
        return;
    };
    address Temp = L->First;

    if (Temp->next == nullptr){
        DelFirst(L, X);
        return;
    };


    while (Temp->next != nullptr) {
        Temp = Temp->next;
    };

    address Prev = Temp->prev;
    Prev->next = nullptr;
    *X = Temp->info;
    Dealokasi(Temp);

};

void CetakAll(List L){
    if (ListEmpty(L)){
        return;
    };

    address Temp = L.First;
    while(Temp->next != nullptr){
        printf("%d -> ", Temp->info);
        Temp = Temp->next;
    };
    printf("%d -> nullptr ", Temp->info);
};
