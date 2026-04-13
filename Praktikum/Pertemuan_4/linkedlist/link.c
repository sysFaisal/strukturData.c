#include "list.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

void CreateList (List *L){
    L->First = NULL;
};

address Alokasi (infotype X){
    address P;
    P = malloc(sizeof(ElmtList));
    if (P == NULL){
        return NULL;
    };
    P->info = X;
    P->next = NULL;
    return P;
};

/*Mengirimkan address hasil alokasi sebuah elemen
Jika alokasi berhasil, maka address !=Nil,
dan misalnya menghasilkan P, maka Info(P)= x, Next(P)=Nil
Jika alokasi gagal, mengirimkan Nil
*/
void DeAlokasi (address P){
    free(P);
    P = NULL;  
};
/*I.S : P terdefinisi
F.S : P dikembalikan ke sistem
Melakukan dealokasi/ pengembalian address P ke system
*/
/** { KELOMPOK OPERASI Cek Elemen kosong atau penuh} **/
boolean ListEmpty(List L){
    return (L.First == NULL);
};
// mengecek apakah jumlah elemen pada List kosong
// mengirimkan true jika List kosong, mengirimkan false jika tidak
/** { KELOMPOK Interaksi dengan I/O device, BACA/TULIS } **/
/**Penambahan Elemen***/
void InsFirst (List *L, infotype X){

    address Curr = L->First;

    if (Curr->next == NULL){
        Curr = Alokasi(X);
        return;
    }

    address Temp = Alokasi(X);

    Temp->next = L->First;
    L->First = Temp;

};
/*I.S : L terdefinisi, mungkin kosong
F.S : melakukan alokasi sebuah elemen dan
menambahkan elemen pertama pada List dengan nilai X jika alokasi
berhasil. Jika alokasi gagal IS = FS
*/
void InsLast (List * L, infotype X){

    address Curr = L->First;

    if (Curr->next == NULL){
        Curr = Alokasi(X);
        return;
    };

    address Temp = Alokasi(X);

    while (Curr->next != NULL){
        Curr = Curr->next;
    };
    Curr->next = Temp;

};
/*I.S : L terdefinisi, mungkin kosong
F.S : melakukan alokasi sebuah elemen dan
menambahkan elemen terakhir pada List dengan nilai X jika alokasi
berhasil. Jika alokasi gagal IS = FS
*/
void InsAfter (List * L, infotype X, infotype Y){

    address Curr = L->First;

    if (Curr->next == NULL){
        Curr = Alokasi(X);
        return;
    };
    
    address Temp = Alokasi(X);
    address Prev = NULL;

    if (Curr->info = Y){
        InsFirst(L, X);
        return;
    };
    
    while (Curr != NULL){
        Prev = Curr;
        Curr = Curr->next; 
        if (Prev->info == Y){
            Temp->next = Curr;
            Prev->next = Temp;
            return;
        };
    };

    if (Prev->next->info == Y){
        InsLast(L, X);
        return;
    };

    printf("Error!");

};
/*I.S : L terdefinisi, mungkin kosong
F.S : melakukan alokasi sebuah elemen dengan nilai x dan
menambahkan elemen list setelah y ditemukan pertama kali pada list
*/
/*Penghapusan Elemen*/
void DelFirst (List * L, infotype *X){

    if (L->First == NULL){
        return;
    };

    address Curr = L->First;
    L->First = Curr->next;

    free(Curr);
};
/*I.S : L tidak kosong
F.S : Elemen pertama List dihapus, nilai info disimpan ke X
dan alamat elemen pertama di dealokasi. Sehingga elemen pertama pada List
adalah elemen berikutnya sebelum penghapusan.
*/
void DelLast (List *L, infotype *X){
    if (L->First == NULL){
        return;
    };

    address Curr = L->First;
    address Prev = NULL;

    if (Curr->next == NULL){
        DelFirst(L, X);
    };

    while (Curr != NULL){
        Prev = Curr;
        Curr = Curr->next;
    };


    Prev = NULL;
    DeAlokasi(Curr);
};
/*I.S : L tidak kosong
F.S : Elemen terakhir list dihapus: nilai info disimpan pada X
dan alamat elemen terakhir di dealokasi. Sehingga elemen terakhir pada
List adalah elemen sebelumnya sebelum penghapusan.
*/
void DelAfter (List * L, infotype *X, infotype Y){
    if (L->First == NULL){
        return;
    };

    address Curr = L->First;

    if (Curr->next == NULL){
        DelLast(L, X);
    };

    if (Curr->next->next == NULL){
        DelLast(L, X);
    };

    address Prev = NULL;
    address Mid = NULL;

    while (Curr != NULL){
        Prev = Curr;
        Mid = Curr->next->next;
        Curr = Curr->next;
        if (Prev->info == Y){
            Prev->next = Curr;
            DeAlokasi(Mid);
        };
    };

    printf("Error!");
};
/*I.S : L terdefinisi, mungkin kosong
F.S : melakukan dealokasi sebuah elemen dengan nilai x setelah nilai y

pertama ditemukan pada list.

STRUKTUR DATA
OLEH : TIM DOSEN

Halaman
33 / 81
Nilai x yang dihapus dalam list akan disimpan sebagai keluaran
dari prosedur

*/
void PrintInfo (List L){
    if (L.First == NULL){
        printf("List Kosong");
        return;
    }; 

    address Temp = L.First;

    while (Temp != NULL){
        printf("%d -> ", Temp->info);
        Temp = Temp->next;
    };

    printf("NULL");
};
/* I.S : L terdefinisi, mungkin kosong
F.S : Jika List tidak kosong, menampilkan semua info yang disimpan pada
elemen list ke layar. jika List kosong, hanya menampilkan pesan
“list kosong”

*/
/** KELOMPOK OPERASI LAIN TERHADAP TYPE **/
int NbElmt (List L){
    if (L.First == NULL){
        return 0;
    };

    address Temp = L.First;
    int counter = 1;
    while (Temp != NULL){
        Temp = Temp->next;
        counter = counter + 1;
    };
    return counter;
};
// Mengirimkan banyaknya elemen List atau mengirimkan 0 jika List kosong
address Search (List L, infotype X);
/* Mencari apakah ada elemen list dengan Info (P)= X
Jika ada, mengirimkan address elemen tersebut yang pertama kali
ditemukan.
jika tidak ada, mengirimkan Nil
*/
void InversList (List *L){
    if (L->First == NULL){
        return;
    };

    address Curr = L->First;
    address Prev = NULL;

    if (Curr->next == NULL){
        return;
    };

    int flag = 0;
    
    while (Curr != NULL){
        Prev = Curr;
        Curr = Curr->next;

        if (flag == 0){
            Prev->next = NULL;
            flag = 1;
        };
        Prev->next = Prev;
    };

    if (Curr->next == NULL){
        Curr->next = Prev;
        L->First = Prev;
    };
};
/* I.S : L sembarang
F.S : Mengubah Elemen list menjadi terbalik, yaitu elemen terakhir
menjadi elemen pertama, elemen kedua menjadi elemen sebelum
terakhir dst
Membalik elemen list, tanpa melakukan alokasi / dealokasi

*/
List getNewInversList (List L);
// Mengirimkan list baru, hasil invers dari L
#endif