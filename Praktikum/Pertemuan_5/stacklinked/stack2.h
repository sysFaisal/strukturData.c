/* Program : stack2.h
Author : 
    1. 2550081098, Faisal Fajari,
    2. 2550081000, Lorem Ipsum
    3. 2550081000, Ipsum Dolor 
Kelas : E
Deskripsi: Header file dari prototype stack pointer
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