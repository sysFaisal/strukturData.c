/* Program : doubleLinkList.h
Author : 2550081098, Faisal Fajari
Kelas : E
Deskripsi: Header file dari prototype double linked list
Tanggal : 26/5/2026
*/
/* ADT double Linear Linked List
pembentukan tipe List Linier dan operasi bagi List
Representasi fisik List dengan pointer
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
/* Mengirim TRUE jika list kosong */
void CreateList(List *L);
/* Membentuk sebuah list kosong */
address Alokasi(infotype X);
/* Menghasilkan address alokasi sebuah elemen */
void Dealokasi(address P);
/* Melakukan dealokasi/pengembalian address P */
address Search(List L, infotype X);
/* Menghasilkan address yang mengandung infotype X, jika tidak ada
menghasilkan Nil */
void AddInElm(List *L, infotype X, infotype Y);
void AddFirst(List *L, infotype X);
/* Menambahkan elemen X pada elemen pertama List */
void AddLast(List *L, infotype X);
/* Menambahkan elemen X pada elemen terakhir List */
void DelFirst(List *L, infotype *X);
/* Menghapus elemen pertama List */
void DelLast(List *L, infotype *X);
/* Menghapus elemen terakhir List */
void CetakAll(List L);

#endif