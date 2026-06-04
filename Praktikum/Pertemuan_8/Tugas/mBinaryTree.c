/*
Program : mBinaryTree.c
Author : Faisal Fajari - 2550081098
Kelas : E
Deskripsi: Main file untuk testing semua fungsi binary tree
Tanggal :
*/
#include "bTree.h"
#include <stdio.h>
#include <stdlib.h>

void printMenu(){
    printf("\n=== Binary Tree ===\n");
    printf("1. Insert Elemen ke Pohon\n");
    printf("2. Tampilkan Tinggi Pohon\n");
    printf("3. Traversal PreOrder\n");
    printf("4. Traversal InOrder\n");
    printf("5. Traversal PostOrder\n");
    printf("6. Tampilkan Root\n");
    printf("7. Tampilkan Info Child Kiri dan Kanan dari Root\n");
    printf("8. Input Batch dan Tampilkan Semua\n");
    printf("0. Keluar\n");
    printf("===================\n");
    printf("Pilihan: ");
}

int main(){
    Tree MyPohon = nil;
    int pilihan, nilai;
    Tree tempLeft, tempRight;
    int rootValue;

    system("cls");
    
    do {
        printMenu();
        scanf("%d", &pilihan);
        
        switch(pilihan){
            case 1:
                printf("Masukkan nilai yang ingin diinsert: ");
                scanf("%d", &nilai);
                MyPohon = InsSearch(MyPohon, nilai);
                printf("Nilai %d berhasil diinsert\n", nilai);
                break;
                
            case 2:
                if(MyPohon != nil){
                    printf("Tinggi Pohon: %d\n", TinggiPohon(MyPohon));
                } else {
                    printf("Pohon masih kosong!\n");
                }
                break;
                
            case 3:
                if(MyPohon != nil){
                    printf("PreOrder Traversal:\n");
                    PreOrder(MyPohon);
                } else {
                    printf("Pohon masih kosong!\n");
                }
                break;
                
            case 4:
                if(MyPohon != nil){
                    printf("InOrder Traversal:\n");
                    InOrder(MyPohon);
                } else {
                    printf("Pohon masih kosong!\n");
                }
                break;
                
            case 5:
                if(MyPohon != nil){
                    printf("PostOrder Traversal:\n");
                    PostOrder(MyPohon);
                } else {
                    printf("Pohon masih kosong!\n");
                }
                break;
                
            case 6:
                if(MyPohon != nil){
                    rootValue = getRoot(MyPohon);
                    printf("Nilai Root: %d\n", rootValue);
                } else {
                    printf("Pohon masih kosong!\n");
                }
                break;
                
            case 7:
                if(MyPohon != nil){
                    printf("Root: %d\n", getRoot(MyPohon));
                    tempLeft = getLeft(MyPohon);
                    tempRight = getRight(MyPohon);
                    if(tempLeft != nil){
                        printf("Child Kiri: %d\n", getRoot(tempLeft));
                    } else {
                        printf("Child Kiri: kosong\n");
                    }
                    if(tempRight != nil){
                        printf("Child Kanan: %d\n", getRoot(tempRight));
                    } else {
                        printf("Child Kanan: kosong\n");
                    }
                } else {
                    printf("Pohon masih kosong!\n");
                }
                break;
                
            case 8:
                printf("Masukkan bilangan (akhiri dengan 9999):\n");
                do {
                    printf("Input: ");
                    scanf("%d", &nilai);
                    if(nilai != 9999){
                        MyPohon = InsSearch(MyPohon, nilai);
                    }
                } while(nilai != 9999);
                
                printf("\nPreOrder:\n");
                PreOrder(MyPohon);
                printf("\nInOrder:\n");
                InOrder(MyPohon);
                printf("\nPostOrder:\n");
                PostOrder(MyPohon);
                printf("\nTinggi Pohon: %d\n", TinggiPohon(MyPohon));
                break;
                
            case 0:
                printf("Terima kasih!\n");
                break;
                
            default:
                printf("Pilihan tidak valid!\n");
        }
        
        if(pilihan != 0){
            printf("\nTekan Enter untuk melanjutkan...");
            getchar(); // consume newline
            getchar();
        }
    } while(pilihan != 0);
    
    return 0;
}
