#include <iostream>
#include "listvoucher.h"
#include <fstream>


int main (){
    string file = "Teori/Tubes/dataVoucher.txt";
    linkList L = createList();

    loadStoack(&L, file);
    cetaklinkList(L);
    editStock(&L, "005", 5);
    cetaklinkList(L);

};