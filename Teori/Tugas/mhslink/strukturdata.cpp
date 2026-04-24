#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <string.h>
#include <stdbool.h>
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
using namespace std;

int main(){
    string namaFile = "Teori/Tugas/mhslink/data.txt";
    ifstream file (namaFile); SLL *L;

    if (!initall(&L, file)){
        return -1;
    };

    loadToNode(L, file);
    cetakNode(L);

    getchar();
    getchar();
    
};

