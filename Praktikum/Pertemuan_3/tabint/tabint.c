#include <stdio.h>
#include "boolean.h"
#include "tabint.h"

void CreateTabInt (TabInt *T){
    T->nEff = 0;
};


int GetJumElmt(TabInt T){
    if (T.nEff == 0){
        return 0;
    };
    return T.nEff;
};

int GetFirstIdx (TabInt T){
    if (T.nEff == 0){
        return 0;
    };
    return T.T1[1];
};

int GetLastIdx (TabInt T){
    if (T.nEff == 0){
        return 0;
    };
    return T.T1[T.nEff];
};

int GetElmt (TabInt T, int idx){
    if (idx >= 1 && idx <= T.nEff){
        return T.T1[idx];
    };
    return IdxUndef;
};


void SetEl(TabInt *T,int i, int v ){
    if (i >= 1 && i <= nMax){
        T->T1[i] = v;
    };
};


boolean IsEmpty(TabInt T){
    if (T.nEff == 0){
        return true;
    };
    return false;
};

boolean IsFull(TabInt T){
    if (T.nEff >= nMax){
        return true;
    };
    return false;
};


void BacaElmt (TabInt *T){
    if (!(T->nEff >= nMax)){
        T->nEff = T->nEff + 1;
        printf("\nMasukan nilai elemen baru : ");
        scanf("%d", &T->T1[T->nEff]);
    };
};

void CetakTabInt(TabInt T){
    int i;
    for (i = 1; i <= T.nEff; i++){
        printf("%d\n", T.T1[i]);
    };
};

void AddElmt(TabInt *T, int X){
    if (!(T->nEff >= nMax)){
        T->nEff = T->nEff + 1;
        T->T1[T->nEff] = X;
    };
};


TabInt KaliTab (TabInt T1, TabInt T2){
    TabInt Temp;
    CreateTabInt(&Temp); int i;

    if (T1.nEff == T2.nEff){
        for (i = 1; i <= T1.nEff; i++){
            AddElmt(&Temp, T1.T1[i] * T2.T1[i]);
        };
    };
    
    return Temp;
};

TabInt KaliKons (TabInt T, int c){
    TabInt Temp; int i;
    CreateTabInt(&Temp);

    for (i = 1; i <= T.nEff; i++){
        AddElmt(&Temp, T.T1[i] * c);
    };

    return Temp;
};


boolean IsEQTab(TabInt T1, TabInt T2){  
    int i;

    if (T1.nEff != T2.nEff){
        return false;
    };

    for (i = 1; i <= T1.nEff; i++){
        if (T1.T1[i] != T2.T1[i]){
            return false;
        };
    };

    return true;
};


void CopyTab(TabInt Tin, TabInt *Tout){
    *Tout = Tin;
};

TabInt InverseTab(TabInt T){
    TabInt Temp;

    CreateTabInt(&Temp);
    CopyTab(T, &Temp);

    int i; ElType tempInt;

    for (i = 1; i <= Temp.nEff / 2; i++){
        tempInt = Temp.T1[i];
        Temp.T1[i] = Temp.T1[Temp.nEff - i + 1];
        Temp.T1[Temp.nEff - i + 1] = tempInt;
    };

    return Temp;
};

boolean isElemenAda(TabInt T, ElType X){
    int i;
    for (i = 1; i <= T.nEff; i++){
        if (T.T1[i] == X){
            return true;
        };
    };
    return false;
};

int cariElemen(TabInt T, ElType X){
    int i;
    for (i = 1; i <= T.nEff; i++){
        if (T.T1[i] == X){
            return i;
        };
    };
    return IdxUndef;
};
