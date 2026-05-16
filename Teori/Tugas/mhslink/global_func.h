#ifndef _Global_H
#define _Global_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>
#include <stdbool.h>

using namespace std;

struct NodeSingle{
    int nim;
    string name;
    string Jurusan;
    float ipk;
    struct NodeSingle *Next;
};

struct NodeDouble{
    int nim;
    string name;
    string jurusan;
    float ipk;
    struct NodeDouble *Next;
    struct NodeDouble *Prev;
};

struct DLL{
    struct NodeDouble *first;
};

struct SLL{
    struct NodeSingle *first;
};

bool openFile(ifstream &File);
bool cekFile(ifstream &File);
bool CekFileAll(int totalFileRead, int totalFileWrite, string readFile[], string writeFile[]);

SLL initSingle();
DLL initDouble();

NodeSingle *addNodeSingle(int nim, string jurusan, string nama, float ipk);
void insertFirstNodeSingle(SLL *S, int nim, string jurusan, string nama, float ipk);
void printfileSingle(string readFile);
void loadToNodeSingle(SLL *S, string readFile);
void filterNodeSingle(SLL *S, float ipk);
void saveToFileSingle(SLL *S, string writeFile);
void cetakNodeSingle(SLL *S);

NodeDouble* addNodeDouble(int nim, string jurusan, string nama, float ipk);
void insertFirstNodeDouble(DLL *D,int nim, string jurusan, string nama, float ipk);
void printfileDouble(string readFile);
void loadtoNodeDouble(DLL *D, string readFile);
void sortNodeDouble(DLL *D);
void saveToFileDouble(DLL *D, string writeFile);
void cetakNodeDouble(DLL *D);

inline void loopclearFile(int totalWriteFile, string writeFile[]){
    int counter = 0;
    for(counter = 0; counter < totalWriteFile; counter++){
        ofstream file(writeFile[counter], ios::out | ios::trunc);  
    };
};


#endif
