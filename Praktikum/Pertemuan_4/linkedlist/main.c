/* Program : main.c
Author : 2550081098, Faisal Fajari
Kelas : E
Deskripsi: Main driver dari prototype Linked List
Tanggal : 13/04/2026
*/

#include <stdio.h>
#include "list.h"

int main (){
    List L1, L2, L3, L4, L5;
    infotype node = 0;
    address TempC = NULL;

    int i,n = 0;
    CreateList(&L1);
    printf("--- Search ---\n");
    printf("Masukan Total Node Yang Ingin Dimasukan : "); scanf("%d",&n);
    for (i = 0; i < n; i++){
        printf("Node %d : ", i + 1);
        scanf("%d", &node);
        InsFirst(&L1, node);
    };
    printf("L1 : "); PrintInfo(L1);

    infotype temp1 = 0, temp2 = 0;
    printf("Masukan Angka yang ingin dimasukan di Node Akhir : "); scanf("%d", &temp1);
    InsLast(&L1, temp1);
    printf("L1 : "); PrintInfo(L1);
    printf("Masukan Angka yang ingin dimasukan : "); scanf("%d", &temp1);
    printf("Setelah Angka : "); scanf("%d", &temp2);
    InsAfter(&L1 , temp1, temp2);

    printf("L1 : "); PrintInfo(L1);
    printf("Inverse L1 : ");
    L2 = getNewInversList(L1);
    PrintInfo(L2);

    printf("\n--- Delete Node ---\n");
    L3 = getNewInversList(L2);
    L4 = getNewInversList(L2);
    L5 = getNewInversList(L2);

    infotype datl3 = 0, datl4 = 0, datl5 = 0;
    infotype temp = 0;

    DelFirst(&L3, &datl3);
    DelLast(&L4, &datl4);

    printf("DelFirst L1 : "); PrintInfo(L3);
    printf("- Node Berisi %d dihapus\n", datl3);
    printf("- Size List : %d\n", NbElmt(L3));

    printf("\nDelLast L1 : "); PrintInfo(L4);
    printf("- Node Berisi %d dihapus\n", datl4);
    printf("- Size List : %d\n", NbElmt(L4));

    printf("\nList L1 : ");
    PrintInfo(L1);
    printf("Masukan Node yang ingin dihapus setelah Angka : "); scanf("%d", &temp);
    DelAfter(&L5, &datl5, temp);
    printf("DelAfter L1 : "); PrintInfo(L5);
    printf("- Node Berisi %d dihapus\n", datl5);
    printf("- Size List : %d\n", NbElmt(L5));

    printf("\n--- Search ---\n");
    printf("List L1 : ");
    PrintInfo(L1);
    infotype cari = 0;
    printf("Cari Element : "); scanf("%d", &cari);
    TempC = Search(L1, cari);
    if (TempC == NULL){
        printf("Tidak Ada element %d dalam L1", cari);
    } else {
        printf("Terdapat element %d dalam L1\n", cari);
    };

    getchar();
    getchar();

};