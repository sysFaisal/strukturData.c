/* Program : main.c
Author : 2550081098, Faisal Fajari
Kelas : E
Deskripsi: Main driver dari prototype Linked List
Tanggal : 13/04/2026
*/

#include <stdio.h>
#include "list.h"

int main (){
    List L1;
    CreateList(&L1);
    InsLast(&L1, 1);
    InsLast(&L1, 2);
    InsLast(&L1, 3);
    InsLast(&L1, 4);
    PrintInfo(L1);


};