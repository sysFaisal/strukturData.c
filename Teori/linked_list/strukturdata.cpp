#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "func.h"

/* Func
SLL* initNode();
Node *addNode(int dat);
void insertLastNode(SLL *L, int data);
void insertFirstNode(SLL *L, int data);
int sizeListNode(SLL *L);
void deleteLastNode(SLL *L);
int cariNode(SLL *L, int target);
void cetakNode(SLL *L);
*/
int main(){

    SLL *L = initNode();
    insertLastNode(L, 1);
    insertFirstNode(L, 2);
    insertFirstNode(L, 3);
    insertFirstNode(L, 4);
    insertFirstNode(L, 5);
    insertFirstNode(L, 6);
    cetakNode(L);
    if (cariNode(L,7)){
        printf("Ada di Node : %d\n", cariNode(L,4));
    };
    printf("Size List : %d\n", sizeListNode(L));


    getchar();
    getchar();
};

