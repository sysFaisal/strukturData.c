#include "boolean.h"
#include "point.h"
#include "line.h"
#include <stdio.h>
#include <conio.h>

int GetGradient(Line L){
    int x1, x2;
    int y1, y2;

    x1 = L.PAwal.x;
    x2 = L.PAkhir.x;

    y1 = L.PAwal.y;
    y2 = L.PAkhir.y;

    if ((x2 - x1) == 0){
        return -1;
    }

    return (y2 - y1) / (x2 - x1);
};

void CreateLine (Line *L){
    CreatePOINT(&L->PAwal);
    CreatePOINT(&L->PAkhir);
};

void CreateLINE2 (Line *L, POINT First, POINT End){
    L->PAwal.x = First.x;
    L->PAwal.y = First.y;

    L->PAkhir.x = End.x;
    L->PAkhir.y = End.y;
};


POINT GetPAwal(Line L){
    return L.PAwal;
};

POINT GetPAkhir (Line L){
    return L.PAkhir;
};


void SetPAwal(Line *L, POINT newFirstP){
    L->PAwal.x = newFirstP.x;
    L->PAwal.y = newFirstP.y;
};
void SetPAkhir (Line *L, POINT newEndP){
    L->PAkhir.x = newEndP.x;
    L->PAkhir.y = newEndP.y;
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


boolean IsEQLine(Line Ll, Line L2){
    return EQ(Ll.PAwal, L2.PAwal);
};

boolean IsNEQLine(Line P1, Line P2){
    return NEQ(P1.PAwal, P2.PAwal);
};


boolean IsLOnSbX (Line L){
    return (L.PAwal.x == L.PAkhir.x);
};

boolean IsLOnSbY (Line L){
    return (L.PAwal.y == L.PAkhir.y);
};



boolean IsTegakLurus(Line L1, Line L2){
    int Gradient1 = GetGradient(L1);
    int Gradient2 = GetGradient(L2);

    if (Gradient1 * Gradient2 == -1) {
        return true;
    } else {
        return false;
    }

};

boolean IsSejajar(Line L1, Line L2){
    int Gradient1 = GetGradient(L1);
    int Gradient2 = GetGradient(L2);

    if (Gradient1 == Gradient2) {
        return true;
    } else {
        return false;
    }
};

void GeserLine (Line *L, int deltaX, int deltaY){
    L->PAwal.x = L->PAwal.x + deltaX;
    L->PAwal.y = L->PAwal.y + deltaY;

    L->PAkhir.x = L->PAkhir.x + deltaX;
    L->PAkhir.y = L->PAkhir.y + deltaY;
};
