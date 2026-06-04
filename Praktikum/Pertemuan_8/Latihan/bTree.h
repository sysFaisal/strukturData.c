/*
Program : bTree.h
Author : Faisal Fajari - 2550081098
Kelas : E
Deskripsi: Header file dari prototype binary tree
Tanggal :
*/

#ifndef BTREE_H
#define BTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define nil NULL
#define info(P) (P)->info
#define left(P) (P)->left
#define right(P) (P)->right

typedef struct tNode *address;
typedef struct tNode{
    int info;
    address left;
    address right;
} Node;

typedef address Tree;


void CreateTree(Tree *T, int x, Tree L, Tree R);
address Alokasi(int X);
void DeAlokasi(address P);


int getRoot(Tree T);
Tree getLeft(Tree T);
Tree getRight(Tree T);
int TinggiPohon(Tree T);
int Maksimum(int Kiri, int Kanan);


Tree InsSearch(Tree T, int x);
void CetakTree(Tree T);
void PreOrder(Tree T);
void InOrder(Tree T);
void PostOrder(Tree T);

#endif 
