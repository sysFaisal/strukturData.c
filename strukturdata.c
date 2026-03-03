#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void newNode(Node **Head, int dat){
    Node *New = (Node *)malloc(sizeof(Node));
    New->data = dat;
    New->next = NULL;

    if (*Head == NULL){
        *Head = New;
        return;
    }

    Node *Temp = *Head;
    while (Temp->next != NULL){
        Temp = Temp->next;
    }
    Temp->next = New;

}

void cekNode(Node **Head){
    Node *Temp = *Head;
    while (Temp != NULL){
        printf("%d [%p] -> %p\n", 
        Temp->data, 
        (void*)Temp, 
        (void*)Temp->next);
        Temp = Temp->next;
    }
}

void gabungNode(Node **Head, Node **Head1){
    Node *ngab = *Head;
    while (ngab->next != NULL){
        ngab = ngab->next;
    }
    ngab->next = *Head1;
}

int main (){
    Node *Head = NULL;
    Node *Head1 = NULL;
    for (int i = 0; i < 3; i++){
        newNode(&Head, i);
    }
    for (int i = 0; i < 3; i++){
        newNode(&Head1, 3-i);
    }

    gabungNode(&Head, &Head1);
    printf("DONE");
    cekNode(&Head);
    getchar();
    getchar();
}
