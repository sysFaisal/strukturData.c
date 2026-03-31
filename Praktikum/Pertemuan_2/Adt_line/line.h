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
void CreateLINE2 (Line *L, POINT First, POINT End);

POINT GetPAwal(Line L);
POINT GetPAkhir (Line L);

void SetPAwal(Line *L, POINT newFirstP);
void SetPAkhir (Line *L, POINT newEndP);

void BacaLine (Line *L);
void CetakLine(Line L);

boolean IsEQLine(Line L1, Line L2);
boolean IsNEQLine(Line P1, Line P2);

boolean IsLOnSbX (Line L);
boolean IsLOnSbY (Line L);
boolean IsTegakLurus(Line L1, Line L2);
boolean IsSejajar(Line L1, Line L2);

void GeserLine (Line *L, int deltaX, int deltaY);

#endif 


