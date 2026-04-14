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
void deleteTargetNode(DLL *L, int target);

void cariNode(DLL *L, int target);
void reverseList(DLL *L);
void updateNode(DLL *L, int data, int position);
*/

int main(){
    DLL *L = initDLL();
    insertLastNode(L, 0);
    insertLastNode(L, 1);
    insertLastNode(L, 2);
    cetakNextNode(L);
    cetakPrevNode(L);
    reverseList(L);
    cetakNextNode(L);
    cetakPrevNode(L);

    getchar(); getchar();
};