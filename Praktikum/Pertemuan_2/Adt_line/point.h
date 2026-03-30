#ifndef _POINT_H
#define _POINT_H

#include "boolean.h"

#define Absis(P) (P).x
#define Ordinat(P) (P).y
#define PI 3.14159265


typedef struct{
    int x;
    int y;
}POINT;

void CreatePOINT (POINT *p);
void CreatePOINT2 (POINT *p, int XBaru, int YBaru);

int GetAbsis(POINT p);
int GetOrdinat(POINT p);

void SetAbsis(POINT *p, int newX);
void SetOrdinat(POINT *p, int newY);

void BacaPOINT(POINT *p);
void CetakPOINT(POINT p);

boolean EQ (POINT p1, POINT p2);
boolean NEQ (POINT p1, POINT p2);
boolean LT (POINT p1, POINT p2); 
boolean MT (POINT p1, POINT p2);


boolean IsOrigin(POINT p);
boolean IsOnSbx(POINT p);
boolean IsOnSby(POINT p);
int Kuadran(POINT p);

POINT MirrorOf(POINT p, boolean Sbx, boolean Sby);
float Jarak0(POINT p);
void GeserKeSbX (POINT *p);
void GeserKeSbY (POINT *p);

#endif