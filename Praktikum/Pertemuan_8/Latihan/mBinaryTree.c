/*
Program : mBinaryTree.c
Author : Faisal Fajari - 2550081098
Kelas : E
Deskripsi: Body file dari prototype
Tanggal :
*/
#include "bTree.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Tree MyPohon = nil;
    int N;

    system("cls");
    printf("Masukan Bilangan : ");
    scanf("%d", &N);

    while(N != 9999){
        MyPohon = InsSearch(MyPohon, N);
        printf("Masukan Bilangan : ");
        scanf("%d", &N);
    }

    printf("Pengurutan PreOrder :"); PreOrder(MyPohon); printf("\n");
    printf("Pengurutan InOrder :"); InOrder(MyPohon); printf("\n");
    printf("Pengurutan PostOrder :"); PostOrder(MyPohon); printf("\n");
    printf("\nTinggi Pohon : %d", TinggiPohon(MyPohon));
    getchar();
    return 0;
}
