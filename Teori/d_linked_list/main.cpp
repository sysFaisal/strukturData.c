#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "func.h"

/* Func
DLL* initDLL();
Node* addNode(int data);
void insertLastNode(DLL *L, int data);
void insertFirstNode(DLL *L, int data);
void insertTargetNode(DLL *L, int data, int position);

void cetakNextNode(DLL *L);
void cetakPrevNode(DLL *L);
int sizeListNode(DLL *L);

void deleteLastNode(DLL *L);
void deleteFirstNode(DLL *L);
void deleteTargetNode(DLL *L, int data);

void cariNode(DLL *L, int target);
void reverseList(DLL *L);
void updateNode(DLL *L, int data, int position);
*/

int main(){

    DLL *L = initDLL();
    insertLastNode(L, 1);
    insertLastNode(L, 2);
    insertLastNode(L, 3);
    insertLastNode(L, 4);
    insertFirstNode(L, 0);
    deleteTargetNode(L, 3);
    printf("Total List : %d\n", sizeListNode(L));
    cetakNextNode(L);
    cetakPrevNode(L);
    reverseList(L);
    updateNode(L, 9, 3);
    cetakNextNode(L);
    cetakPrevNode(L);


    getchar(); 
    getchar();
};