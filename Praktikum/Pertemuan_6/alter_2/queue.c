/* Program : queue.h
Author : 2550080198_Faisal Fajari
Kelas : E
Deskripsi: Body file dari prototype queue
Tanggal : 18/5/26
*/
#include "queue.h"
#include "boolean.h"
#include "stdio.h"
#define Nil 0
#define MaxEl 10

void CreateQueue(Queue *Q){
    Q->HEAD = Nil;
    Q->TAIL = Nil;
    int counter = 0;
    for (counter = 0; counter <= MaxEl; counter++){
        Q->T[counter] = Nil;
    };
};

boolean IsQueuekEmpty (Queue Q){
    return ((Q.HEAD > Q.TAIL) || ((Q.HEAD == Nil) && (Q.TAIL == Nil)));
};

int NBElmt(Queue Q){
    if (IsQueuekEmpty(Q)){
        return 0;
    } else {
        return (Q.TAIL - Q.HEAD + 1);
    }
};

boolean IsQueuekFull(Queue Q){
    return (Q.TAIL == MaxEl);
};

void AddQueue (Queue *Q, infotype X){

    if (IsQueuekEmpty(*(Q))){
        Q->HEAD = 1;
        Q->TAIL = 1;
        Q->T[Q->TAIL] = X;
        return;
    };

    if (!IsQueuekFull(*(Q))){
        Q->TAIL = Q->TAIL + 1;
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
    Q->HEAD = Q->HEAD + 1;

    /*
    *X = Q->T[Q->HEAD];
    Q->T[Q->HEAD] = Nil;
    Q->HEAD = Q->HEAD + 1;

    if (Q->HEAD > Q->TAIL){
        Q->HEAD = Nil;
        Q->TAIL = Nil;
    };
    */
    
    return;
}

void PrintQueueInfo (Queue S){
    if (IsQueuekEmpty(S)){
        printf("\nQueue Kosong! \n");
        return;
    };

    printf("Isi Queue : ");
    int counter = 0;
    for (counter = S.HEAD; counter <= S.TAIL; counter++){
        printf("%d ", S.T[counter]);
    };
    printf("\n");

};

boolean isInfoKetemu(Queue S, infotype X){
    if (IsQueuekEmpty(S)){
        return false;
    };

    int counter = 0;
    for (counter = S.HEAD; counter <= S.TAIL; counter++){
        if (S.T[counter] == X){
            return true;
        };
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
