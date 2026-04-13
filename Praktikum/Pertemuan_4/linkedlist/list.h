/*
Program : list.h
Author : 2550081098, Faisal Fajari
Kelas : E
Deskripsi: Header file dari prototype linear linked list
Tanggal : 13/4/2026
*/

#ifndef _LIST_H
#define _LIST_H
#include "boolean.h"
#include <stdio.h>
#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First

typedef struct tElmtList *address;

typedef int infotype;

typedef struct tElmtList{
    infotype info;
    address next;
} ElmtList;

typedef struct{
    address First;
} List;


void CreateList (List *L);

address Alokasi (infotype X);

void DeAlokasi (address P);

boolean ListEmpty(List L);

void InsFirst (List *L, infotype X);

void InsLast (List * L, infotype X);

void InsAfter (List * L, infotype X, infotype Y);

void DelFirst (List * L, infotype *X);

void DelLast (List *L, infotype *X);

void DelAfter (List * L, infotype *X, infotype Y);

void PrintInfo (List L);

int NbElmt (List L);

address Search (List L, infotype X);

void InversList (List *L);

List getNewInversList (List L);

#endif