#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insertLast_Node(Node **Head, int dat){
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

};

void insertFirst_Node(Node **Head, int data){
    Node *New = (Node *)malloc(sizeof(Node));
    New->data = data;
    New->next = *Head;

    *Head = New;

};

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
    char *list = "12345";
    printf("Total Lenght = %lld\n", strlen(list));
    char temp[2];

    for (int i = 0; i < strlen(list); i++){
        temp[0] = list[i];
        temp[1] = '\0';
        printf("%d ", atoi(temp));

        if (i == strlen(list) - 1 ){
            printf("\n");
        }
        insertLast_Node(Head, atoi(temp));
    }
    
};

void pisahNode(Node **Head){
    int target = 7;
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

int insertMid_Node(Node **Head, int targetSplit, int data){
    Node *New = (Node *)malloc(sizeof(Node));
    Node *Temp1 = NULL;
    Node *Temp = *Head;

    New->data = data;

    while(Temp->next != NULL){

        if (Temp->data == targetSplit){
            Temp1 = Temp->next;
            break;
        } else {
            Temp = Temp->next;
        }
    };

    New->next = Temp1;
    Temp->next = New;
    return Temp->data;
};

void insertNode(Node **Head){
    int targetSplit = 3;
    int data = 20; 
    insertMid_Node(Head, targetSplit, data);
    //insertFirst_Node(Head, data);
    //insertLast_Node(Head, data);
};

void reverseNode(Node **Head){
    Node *Curent = *Head;
    Node *Prev = NULL;
    Node *Nex = NULL;

    while(Curent->next != NULL){
        Nex = Curent->next;
        Curent->next = Prev;
        Prev = Curent;
        Curent = Nex;
    };

    *Head = Prev;

};
void deleteMid_Note(Node **Head, int Target){
    Node *Curent = *Head;
    Node *Temp = NULL;
    Node *Prev = NULL;

    while(Curent->next != NULL){

        if (Curent->data == Target){
            Temp = Curent->next;
        } else {
            Curent = Curent->next;
        };

    };

    *Head = Prev;
};

void deleteFirst_Node(Node **Head){
    Node *Curent = *Head;
    *Head = Curent->next;
    free(Curent);
    Curent = NULL;
};

void deleteLast_Node(Node **Head){
    if (*Head == NULL) return;

    Node *Current = *Head;
    Node *Prev = NULL;

    while(Current->next != NULL){
        Prev = Current;
        Current = Current->next;
    }

    if (Prev == NULL){
        *Head = NULL;
    } else {
        Prev->next = NULL;
    }

    free(Current);
    Current = NULL;
    /*
    Node *Curent = *Head;
    Node *Nex = NULL;
    while(Curent->next != NULL){
        Curent = Curent->next;
        Nex = Curent->next;
        if (Nex->next == NULL){
            Curent->next = NULL;
            free(Nex);
            Nex = NULL;
        };
    };
    */
};

void deleteNode(Node **Head){
    int Target = 3;
    //deleteMid_Note(Head, Target);
    //deleteFirst_Node(Head);
    deleteLast_Node(Head);
};

int main (){
    Node *Head = NULL;

    inputNode(&Head);
    cekNode(&Head);
    deleteNode(&Head);
    //pisahNode(&Head);
    //insertNode(&Head);
    //reverseNode(&Head);
    cekNode(&Head);


    /* 
    cekNode(&Head);
    */
    getchar();
    getchar();
    
}
