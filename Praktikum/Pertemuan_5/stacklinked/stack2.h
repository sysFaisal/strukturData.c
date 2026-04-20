/* Program : stack2.h
Author : 2550081098, Faisal Fajari
Kelas : E
Deskripsi: Header file dari prototype stack linked list
Tanggal : 21/04/2026
*/
#ifndef _STACK2_H
#define _STACK2_H
#include "boolean.h"
#include <stdio.h>

#define nil NULL
#define info(P)
#define next(P)
#define TOP(S) (S).TOP

typedef int infotype; 
typedef struct tElmStack *address;

typedef struct tElmStack{
    infotype Info;
    address next;
} ElmStack;

typedef struct {
    address BUTTOM;
    address TOP;
} Stack;

void CreateStack(Stack *S);

address Alokasi(infotype x);

boolean IsStackEmpty(Stack S);

boolean CariElemenStack(Stack S, infotype x);

void DeAlokasi(address P);

void Push (Stack *S, infotype X);

void Pop (Stack *S, infotype *X);

void CetakStack(Stack S);

#endif