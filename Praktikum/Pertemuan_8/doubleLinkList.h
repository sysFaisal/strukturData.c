/* Program : doubleLinkList.h
Author : 2550081098, Faisal Fajari
Kelas : E
Deskripsi: Header file dari prototype double linked list
Tanggal : 26/5/2026
*/

#ifndef DoubleLinkList_H
#define DoubleLinkList_H
#include <stdlib.h>
#include "boolean.h"
#define nullptr NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define First(L) ((L).First)

typedef int infotype;
typedef struct telmtlist *address;

typedef struct telmtlist{
    infotype info;
    address next;
    address prev;
}ElmtList;

typedef struct{
    address First;
}List;

boolean ListEmpty(List L);

void CreateList(List *L);
address Alokasi(infotype X);

void Dealokasi(address P);
address Search(List L, infotype X);

void AddInElm(List *L, infotype X, infotype Y);
void AddFirst(List *L, infotype X);
void AddLast(List *L, infotype X);

void DelFirst(List *L, infotype *X);
void DelLast(List *L, infotype *X);

void CetakAll(List L);

#endif