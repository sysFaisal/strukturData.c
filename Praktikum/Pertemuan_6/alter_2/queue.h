/* Program : queue.h
Author : 2550080198_Faisal Fajari
Kelas : E
Deskripsi: Header file dari prototype queue
Tanggal : 18/5/26
*/
#ifndef _QUEUE_H
#define _ QUEUE _H
#include "boolean.h"
#define Nil 0
#define MaxEl 10
#define idxUndef 999

#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]

typedef int infotype;
typedef int address;

typedef struct {
    infotype T[MaxEl+1]; 
    address HEAD; 
    address TAIL;
} Queue;

void CreateQueue(Queue *Q);
int NBElmt(Queue Q);

boolean IsQueuekEmpty (Queue Q);
boolean IsQueuekFull(Queue Q);

void AddQueue (Queue *Q, infotype X);
void DelQueue (Queue *Q, infotype *X);

void PrintQueueInfo (Queue S);

boolean isInfoKetemu(Queue S, infotype X);
address CariElemenQueue(Queue Q, int X);

#endif
