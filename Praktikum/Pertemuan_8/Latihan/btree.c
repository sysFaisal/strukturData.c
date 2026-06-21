/*
Program : bTree.c
Author : Faisal Fajari - 2550081098
Kelas : E
Deskripsi: Body file dari prototype binary tree
Tanggal :
*/

#include <stdio.h>
#include "bTree.h"
#include <stdbool.h>


void CreateTree(Tree *T, int x, Tree L, Tree R){

    *T = Alokasi(x);
    if(*T != nil){
        left(*T) = L;
        right(*T) = R;
    }
}

address Alokasi(int X){
    address P;

    P = (address) malloc(sizeof(Node));
    if(P != nil){
        info(P) = X;
        left(P) = nil;
        right(P) = nil;
    }
    return P;
}

void DeAlokasi(address P){

    free(P);
}

int TinggiPohon(Tree T){

    int tinggi;

    tinggi = 0;
    if(T != nil){
        tinggi = 1 + Maksimum(TinggiPohon(left(T)), TinggiPohon(right(T)));
    }
    return tinggi;
}

int Maksimum(int Kiri, int Kanan){

    if(Kiri > Kanan)
        return Kiri;
    else
        return Kanan;
}

Tree InsSearch(Tree T, int x){

    if(T == nil)
        CreateTree(&T, x, nil, nil);
    else if(x < info(T))
        left(T) = InsSearch(left(T), x);
    else
        right(T) = InsSearch(right(T), x);
    return T;
}

void CetakTree(Tree T){

    if(T != nil){
        printf(" %d", info(T));
    }
}

void PreOrder(Tree T){

    if(T != nil){
        CetakTree(T);
        PreOrder(left(T));
        PreOrder(right(T));
    }
}

void InOrder(Tree T){

    if(T != nil){
        InOrder(left(T));
        CetakTree(T);
        InOrder(right(T));
    }
}

int getRoot(Tree T){

    if(T != nil)
        return info(T);
    else
        return -1; 
}

Tree getLeft(Tree T){

    if(T != nil)
        return left(T);
    else
        return nil;
}

Tree getRight(Tree T){

    if(T != nil)
        return right(T);
    else
        return nil;
}

void PostOrder(Tree T){

    if(T != nil){
        PostOrder(left(T));
        PostOrder(right(T));
        CetakTree(T);
    }
}
