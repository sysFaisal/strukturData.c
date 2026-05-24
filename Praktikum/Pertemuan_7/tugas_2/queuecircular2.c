/* Program : queuecircular2.c
Author : (2550081098, Faisal Fajari)
Kelas : E
Deskripsi: Header file dari prototype queue
Tanggal : 20/5/2026
*/
#include "boolean.h"
#include <stdio.h>
#include "queuecircular2.h"
#include <stdlib.h>

void CreateQueue(Queue *Q){
    Q->HEAD = Nil;
    Q->TAIL = Nil;
    Q->counter = 0;
};
address Alokasi(infotype x){
    address New = malloc(sizeof(ElmStack));
    New->Info = x;
    New->next = Nil;
    return New;
};

int NBElmt(Queue Q){
    return (Q.counter);
};
boolean IsQueuekEmpty (Queue Q){
    return (Q.counter == 0);
};
boolean IsQueuekFull(Queue Q){
    return (Q.counter == MaxEl);
};

void AddQueue (Queue *Q, infotype X){

    address New = Alokasi(X);
    if (IsQueuekEmpty(*(Q))){
        Q->HEAD = New;
        Q->TAIL = New;
        Q->TAIL->next = Q->HEAD;
        Q->counter = Q->counter + 1;
        return;
    };

    if (!IsQueuekFull(*(Q))){
        Q->TAIL->next = New;
        Q->TAIL = New;
        Q->TAIL->next = Q->HEAD;
        Q->counter = Q->counter + 1;
        return;
    };

    printf("\nPenuh Le..");

};

void DelQueue (Queue *Q, infotype *X){
    if (IsQueuekEmpty(*(Q))){
        printf("\nKosong");
        return;
    };

    address Temp = Q->HEAD;
    *X = Temp->Info;

    if (Q->HEAD == Q->TAIL){
        Q->HEAD = Nil;
        Q->TAIL = Nil;
        free(Temp);
        Q->counter = 0;
        return;    
    };

    Q->HEAD = Q->HEAD->next;
    Q->TAIL->next = Q->HEAD;
    Q->counter = Q->counter - 1;

    free(Temp);
    
};

void PrintQueueInfo (Queue Q){
    if(IsQueuekEmpty(Q)){
        printf("\nKosong\n");
        return;
    };

    address Temp = Q.HEAD;
    printf("Isi Queue : ");

    while(Temp->next != Q.HEAD){
        printf("%d ", Temp->Info);
        Temp = Temp->next;
    };
    printf("%d -> Repeat\n", Temp->Info);
    
};

boolean isInfoKetemu(Queue Q, infotype x){
    if(IsQueuekEmpty(Q)){
        printf("\nKosong");
        return false;
    };

    address Temp = Q.HEAD;
    while(Temp->next != Q.HEAD){
        if (Temp->Info == x){
            return true;
        };
        Temp = Temp->next;
    };

    if (Temp->Info == x){
        return true;
    };

    return false;
};

address CariElemenQueue(Queue Q, int X){
    if(IsQueuekEmpty(Q)){
        printf("\nKosong");
        return Nil;
    };

    address Temp = Q.HEAD;
    while(Temp->next != Q.HEAD){
        if(Temp->Info == X){
            return Temp;
        };
        Temp = Temp->next;
    };

    if(Temp->Info == X){
        return Temp;
    };

    return Nil;
};
