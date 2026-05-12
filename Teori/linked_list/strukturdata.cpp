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
    insertFirstNode(L, 1);
    insertFirstNode(L, 2);
    insertFirstNode(L, 3);
    insertFirstNode(L, 4);
    insertLastNode(L, 5);
    deletefirstNode(L);
    cetakNode(L);
    printf("\n");
    printf("Ada di Node : %d\n", cariNode(L,2));
    printf("Size List : %d\n", sizeListNode(L));


    getchar();
    getchar();
};

