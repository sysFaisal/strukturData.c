#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <string.h>
// #include "func.h"

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

using namespace std;

int main(){
    ifstream myfile("Teori/Tugas/mhslink/data.txt");

    if (!myfile.is_open()){
        printf("TIdak ada");
    };

    getchar();
    getchar();
};

