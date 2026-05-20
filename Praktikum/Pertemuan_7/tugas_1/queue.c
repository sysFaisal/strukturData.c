/* Program : queue.h
Author : 2550080198_Faisal Fajari
Kelas : E
Deskripsi: Body file dari prototype queue
Tanggal : 18/5/26
*/
#include "queue.h"
#include "boolean.h"
#include "stdio.h"
#define Nil -1
#define MaxEl 10

void CreateQueue(Queue *Q){
    Q->HEAD = Nil;
    Q->TAIL = Nil;
    int counter = 0;
    for (counter = 0; counter < MaxEl; counter++){
        Q->T[counter] = Nil;
    };
};

boolean IsQueuekEmpty (Queue Q){
    return (Q.HEAD == Nil);
};

int NBElmt(Queue Q){
    if (IsQueuekEmpty(Q)){
        return 0;
    } else {
        return ((Q.TAIL - Q.HEAD + MaxEl) % MaxEl + 1);
    }
};

boolean IsQueuekFull(Queue Q){
    int nextTail = Q.TAIL + 1;
    if (nextTail == MaxEl) nextTail = 0;
    return (nextTail == Q.HEAD);
};

void AddQueue (Queue *Q, infotype X){

    if (IsQueuekEmpty(*(Q))){
        Q->HEAD = 0;
        Q->TAIL = 0;
        Q->T[Q->TAIL] = X;
        return;
    };

    if (!IsQueuekFull(*(Q))){
        Q->TAIL = Q->TAIL + 1;
        if (Q->TAIL == MaxEl) Q->TAIL = 0;
        Q->T[Q->TAIL] = X;
        return;
    };

    printf("\nQueue Penuh! \n");
};

void DelQueue (Queue *Q, infotype *X){
    if (IsQueuekEmpty(*(Q))){
        printf("\nQueue Kosong! \n");
        return;
    };

    *X = Q->T[Q->HEAD];
    Q->T[Q->HEAD] = Nil;
    
    if (Q->HEAD == Q->TAIL){
        CreateQueue(Q);
    } else {
        Q->HEAD = Q->HEAD + 1;
        if (Q->HEAD == MaxEl) Q->HEAD = 0;
    };
    
    return;
}

void PrintQueueInfo (Queue S){
    if (IsQueuekEmpty(S)){
        printf("\nQueue Kosong! \n");
        return;
    };

    printf("Isi Queue : ");
    int counter = S.HEAD;
    while (1){
        printf("%d ", S.T[counter]);
        if (counter == S.TAIL) break;
        counter = counter + 1;
        if (counter == MaxEl) counter = 0;
    };
    printf("\n");

};

boolean isInfoKetemu(Queue S, infotype X){
    if (IsQueuekEmpty(S)){
        return false;
    };

    int counter = S.HEAD;
    while (1){
        if (S.T[counter] == X){
            return true;
        };
        if (counter == S.TAIL) break;
        counter = counter + 1;
        if (counter == MaxEl) counter = 0;
    };

    return false;
};

address CariElemenQueue(Queue Q, int X){
    if(IsQueuekEmpty(Q)){
        return idxUndef;
    };

    int counter = 0;
    for (counter = Q.HEAD; counter <= Q.TAIL; counter++){
        if (Q.T[counter] == X){
            return counter;
        };
    };

    return idxUndef;
};
