/* Program : queuecircular.h
Author : (2550081098, Faisal Fajari)
Kelas : E
Deskripsi: Header file dari prototype queue
Tanggal : 20/5/2026
*/
#ifndef _QUEUECIRCULAR_H
#define _ QUEUECIRCULAR_H
#include "boolean.h"
#include <stdio.h>
#define Nil NULL
#define MaxEl 2

#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]

typedef int infotype; 
typedef struct tElmStack *address;

typedef struct tElmStack{
    infotype Info;
    address next;
} ElmStack;

typedef struct {
    address HEAD;
    address TAIL;
    int counter;
} Queue;

void CreateQueue(Queue *Q);
int NBElmt(Queue Q);
boolean IsQueuekEmpty (Queue Q);
boolean IsQueuekFull(Queue Q);
int NBElmt(Queue Q);
void AddQueue (Queue *Q, infotype X);
void DelQueue (Queue *Q, infotype *X);
void PrintQueueInfo (Queue Q);
boolean isInfoKetemu(Queue Q, infotype x);
address CariElemenQueue(Queue Q, int X);

#endif