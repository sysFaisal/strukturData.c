#include "doubleLinkList.h"
#include <stdio.h>

int main(){
    List Temp;
    CreateList(&Temp);

    int x = 0;
    AddLast(&Temp, 10);
    AddLast(&Temp, 30);
    AddLast(&Temp, 40);
    AddLast(&Temp, 50);
    /*
    AddFirst(&Temp, 40);
    AddFirst(&Temp, 30);
    AddFirst(&Temp, 10);
    */
    CetakAll(Temp);
    printf("\n");
    AddInElm(&Temp, 20, 10);
    DelLast(&Temp, &x);
    CetakAll(Temp);

};
