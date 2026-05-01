#ifndef _Func_H
#define _Func_H
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <string.h>
#include <stdbool.h>

using namespace std;

struct Node{
    int nim;
    string name;
    string jurusan;
    float ipk;
    struct Node *Next;
    struct Node *Prev;
};

struct DLL{
    struct Node *first;
};

DLL* initDLL();

Node* addNode(int data);

bool cekFile(ifstream &File);

bool initall(DLL **L, ifstream &File);

void loadtoNode(DLL *L, ifstream &file);

void sortNode(DLL *L);

void saveToFile(DLL *L, ofstream &file);

void cetakNode(DLL *L);
/*
void insertLastNode(DLL *L, int data);

void insertFirstNode(DLL *L, int data);

void insertTargetNode(DLL *L, int data, int position);

void cetakNextNode(DLL *L);

void cetakPrevNode(DLL *L);

void deleteLastNode(DLL *L);

void deleteFirstNode(DLL *L);

void deleteTargetNode(DLL *L, int target);
*/

#endif