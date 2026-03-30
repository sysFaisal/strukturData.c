#ifndef _LINE_H
#define _LINE_H
#include "boolean.h"
#include "point.h"
#include <stdio.h>
#include <conio.h>

#define FirstPoint(L) (L).PAwal
#define EndPoint(L) (L).PAkhir
#define ErrGrad 99990.0

typedef struct {
    POINT PAwal; 
    POINT PAkhir; 
}Line;


float GetGradient(Line L);

void CreateLine (Line *L);
/* I.S : L terdefinisi, tidak diketahui nilainya
F.S : membentuk sebuah Line dari komponen-komponennya dengan L

diinisialisasi nilainya dengan PAwal = (0,0) dan PAkhir = (0,0) */

void CreateLINE2 (Line *L, POINT First, POINT End);
/* I.S : L terdefinisi, tidak diketahui nilainya
F.S : membentuk sebuah Line dari komponen-komponennya dengan L
diinisialisasi nilainya dengan PAwal = First dan PAkhir = End */


POINT GetPAwal(Line L);
// Mengirimkan komponen Titik Awal dari L
POINT GetPAkhir (Line L);
// Mengirimkan komponen Titik Akhir dari L


void SetPAwal(Line *L, POINT newFirstP);
/* I.S : L terdefinisi, dengan nilainya sembarang
F.S : Mengubah nilai komponen Titik Awal dari L dengan PAwal=newFirstP
*/
void SetPAkhir (Line *L, POINT newEndP);
/* I.S : L terdefinisi, dengan nilainya sembarang
F.S : Mengubah nilai komponen Titik Akhir dari L dengan PAkhir=newEndP
*/

void BacaLine (Line *L);
/* I.S : L terdefinisi, mungkin kosong
F.S : Komponen L dengan nilai PAwal dan PAkhir dari yang dibaca
*/
void CetakLine(Line L);
/* I.S : L terdefinisi, mungkin kosong
F.S : Menampilkan nilai Komponen L ke layar dg format “(P1(X1,Y1) ,
P2(X2,Y2))
*/

boolean IsEQLine(Line L1, Line L2);
// Mengirimkan true jika L1 = L2, yaitu:
// jika titik awal dari L1 sama dengan titik awal dari L2 dan
// titik akhir L1 sama titik akhir dari L2.
boolean IsNEQLine(Line P1, Line P2);
// Mengirimkan true jika PI tidak sama dengan P2, negasi dari EQLine

boolean IsLOnSbX (Line L);
// Menghasilkan true jika L terletak pada sumbu X yaitu titik Awal dan
//titik Akhir dari L berada pada sumbu X, dan false jika sebaliknya
boolean IsLOnSbY (Line L);
// Menghasilkan true jika L terletak pada sumbu Y yaitu titik Awal dan
//titik Akhir dari L berada pada sumbu X, dan false jika sebaliknya
boolean IsTegakLurus(Line L1, Line L2);
// Menghasilkan true jika L1 saling tegak lurus terhadap L2, dan false jika
//sebaliknya. Hint : gunakan gradien Garis.
boolean IsSejajar(Line L1, Line L2);
// Menghasilkan true jika L1 saling “sejajar” terhadap L2, dan false jika
//sebaliknya. Hint : gunakan gradien Garis.

void GeserLine (Line *L, int deltaX, int deltaY);
/* I.S : L terdefinisi, mungkin kosong
F.S : L bergeser sebesar absisnya deltaX dan ordinatnya deltaX
*/

#endif 


