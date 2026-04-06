/* Program : tabint.h
Author : 2550081098, Faisal Fajari
Kelas :
Deskripsi: Header file dari prototype Tab Integer
Tanggal :
*/
#ifndef _TABINT_H
#define _TABINT_H
#include "boolean.h"

#define nMax 10
#define IdxUndef -999
#define ElType int

typedef struct {
    ElType T1[nMax]; // koleksi bilangan bertipe integer
    int nEff; // jumlah data atau elemen pada tabel
}TabInt;

void CreateTabInt (TabInt *T);

int GetJumElmt(TabInt T);
int GetFirstIdx (TabInt T);
int GetLastIdx (TabInt T);
int GetElmt (TabInt T, int idx);

void SetEl(TabInt *T,int i, int v );

boolean IsEmpty(TabInt T);
boolean IsFull(TabInt T);

void BacaElmt (TabInt *T);
void CetakTabInt(TabInt T);
void AddElmt(TabInt *T, int X);

TabInt KaliTab (TabInt T1, TabInt T2);
TabInt KaliKons (TabInt T, int c);
boolean IsEQTab(TabInt T1, TabInt T2);

void CopyTab(TabInt Tin, TabInt *Tout);
TabInt InverseTab(TabInt T);

boolean isElemenAda(TabInt T, ElType X);
int cariElemen(TabInt T, ElType X);

#endif 