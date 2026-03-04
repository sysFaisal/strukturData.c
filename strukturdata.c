#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("\n");
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

void inputNode(Node **Head){
    char *list = "123456789";
    printf("Total Lenght = %lld\n", strlen(list));
    char temp[2];

    for (int i = 0; i < strlen(list); i++){
        temp[0] = list[i];
        temp[1] = '\0';
        printf("%d ", atoi(temp));

        if (i == strlen(list) - 1 ){
            printf("\n");
        }
        newNode(Head, atoi(temp));
    }
    
};

void pisahNode(Node **Head){
    int target = 10;
    Node *temp = *Head;
    Node *temp1 = NULL;
    while(temp->next != NULL){

        if (temp->data == target){
            temp1 = temp->next;
            break;

        } else { temp = temp->next; }
    }

    printf("%d", temp->data);
    temp->next =NULL;
    temp1 = NULL;
};

int main (){
    Node *Head = NULL;

    inputNode(&Head);
    cekNode(&Head);
    pisahNode(&Head);
    cekNode(&Head);

}
