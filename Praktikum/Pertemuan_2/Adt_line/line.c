#include "boolean.h"
#include "point.h"
#include "line.h"
#include <stdio.h>
#include <conio.h>

float GetGradient(Line L){
    float x1, x2;
    float y1, y2;

    x1 = L.PAwal.x;
    x2 = L.PAkhir.x;

    y1 = L.PAwal.y;
    y2 = L.PAkhir.y;

    if ((x2 - x1) == 0){
        return ErrGrad;
    }

    return (y2 - y1) / (x2 - x1);
};

void CreateLine (Line *L){
    CreatePOINT(&L->PAwal);
    CreatePOINT(&L->PAkhir);
};

void CreateLINE2 (Line *L, POINT First, POINT End){
    CreatePOINT2(&L->PAwal, First.x , First.y);
    CreatePOINT2(&L->PAkhir, End.x , End.y);
};


POINT GetPAwal(Line L){
    return L.PAwal;
};

POINT GetPAkhir (Line L){
    return L.PAkhir;
};


void SetPAwal(Line *L, POINT newFirstP){
    SetAbsis(&L->PAwal, newFirstP.x);
    SetOrdinat(&L->PAwal, newFirstP.y);

};
void SetPAkhir (Line *L, POINT newEndP){
    SetAbsis(&L->PAkhir, newEndP.x);
    SetOrdinat(&L->PAkhir, newEndP.y);
};

void BacaLine (Line *L){
    BacaPOINT(&L->PAwal);
    BacaPOINT(&L->PAkhir);
};

void CetakLine(Line L){
    printf("P1(%d, %d) , P2(%d, %d)", 
        L.PAwal.x, L.PAwal.y,
        L.PAkhir.x, L.PAkhir.y 
    );
};


boolean IsEQLine(Line L1, Line L2){
    return (EQ(L1.PAwal, L2.PAwal) && EQ(L1.PAkhir, L2.PAkhir));
};

boolean IsNEQLine(Line P1, Line P2){
    return (!IsEQLine(P1, P2));
};


boolean IsLOnSbX (Line L){
    return (IsOnSbx(L.PAwal) && IsOnSbx(L.PAkhir));
};

boolean IsLOnSbY (Line L){
    return (IsOnSby(L.PAwal) && IsOnSby(L.PAkhir));
};


boolean IsTegakLurus(Line L1, Line L2) {
    float m1 = GetGradient(L1);
    float m2 = GetGradient(L2);

    if ((m1 == ErrGrad && m2 == 0) || (m1 == 0 && m2 == ErrGrad)){
        return (true);
    }

    if (m1 * m2 < -0.99 && m1 * m2 > -1.01) {
        return true;
    }

    return(false);
};

boolean IsSejajar(Line L1, Line L2){
    return (GetGradient(L1) == GetGradient(L2));
};

void GeserLine (Line *L, int deltaX, int deltaY){
    SetAbsis(&L->PAwal, (L->PAwal.x + deltaX));
    SetOrdinat(&L->PAwal, (L->PAwal.y + deltaY));

    SetAbsis(&L->PAkhir, (L->PAkhir.x + deltaX));
    SetOrdinat(&L->PAkhir, (L->PAkhir.y + deltaY));
};
