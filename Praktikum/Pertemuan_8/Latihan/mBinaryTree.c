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

    PreOrder(MyPohon);
    printf("\nTinggi Pohon : %d", TinggiPohon(MyPohon));
    getch();
    return 0;
}
