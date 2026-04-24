#ifndef _Func_H
#define _Func_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>
#include <stdbool.h>

using namespace std;

struct Node{
    int nim;
    string name;
    string Jurusan;
    float ipk; 
    struct Node *Next;
};

struct SLL{
    struct Node *first;
};

SLL* initNode();
Node *addNode(int nim, string jurusan, string nama, float ipk);

bool cekFile(ifstream &File);
bool initall(SLL **L, ifstream &File);
void printfile(ifstream &file);
void loadToNode(SLL *L, ifstream &file);

void insertFirstNode(SLL *L, int nim, string jurusan, string nama, float ipk);
//int sizelistNode(SLL *L);
void cetakNode(SLL *L);

#endif