#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <string.h>
#include <stdbool.h>
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
using namespace std;

int main(){
    string readFile = "Teori/Tugas/mhslink/data.txt";
    string writeFile = "Teori/Tugas/mhs2link/clone.txt";
    ifstream read (readFile);
    ofstream write (writeFile);
    DLL *L;

    if (!initall(&L, read)){
        return -1;
    };
    loadtoNode(L, read);
    sortNode(L);
    cetakNode(L);
    saveToFile(L, write);

    getchar(); 
    getchar();
};