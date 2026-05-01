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
    string readFile = "Teori/Tugas/mhs2link/data.txt";
    string writeFile = "Teori/Tugas/mhslink/clone.txt";
    ifstream read (readFile);
    ofstream write (writeFile);
    SLL *L;

    if (!initall(&L, read)){
        return -1;
    };

    loadToNode(L, read);
    filterNode(L, 3.7);
    cetakNode(L);
    saveToFile(L, write);

    getchar();
    getchar();
    
};

