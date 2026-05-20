/* Program : queue.h
Author : 2550080198_Faisal Fajari
Kelas : E
Deskripsi: Main Driver file dari prototype queue
Tanggal : 18/5/26
*/
#include <stdio.h>
#include "queue.h"
#include <stdlib.h>

int main(){
    Queue Q;
    CreateQueue(&Q);
    int pilihan = 0;
    char fix;

    do {
        system("clear");
        printf("1. AddQueue\n");
        printf("2. DelQueue\n");
        printf("3. CetakQueue\n");
        printf("Pilihan : ");
        scanf("%d",&pilihan);

        switch (pilihan) {
            case 1:
            printf("\n=== AddQueue ===\n");
                while (1){
                    printf("Masukan Element : ");
                    scanf("%d", &pilihan);

                    if (IsQueuekFull(Q)){
                        printf("Queue Penuh...");
                        getchar();
                        getchar();
                        break;
                    };

                    AddQueue(&Q, pilihan);


                    printf("Lagi (y/n) : ");
                    scanf(" %c", &fix);

                    if (fix == 'n' || fix == 'N'){
                        break;
                    };
                };
            break;

            case 2:
                printf("\n=== DelQueue ===\n");
                PrintQueueInfo(Q);
                while (1){
                    
                    printf("\nDequeue (y/n)? : ");
                    scanf(" %c", &fix);

                    if (fix == 'y' || fix == 'Y'){
                        DelQueue(&Q, &pilihan);
                    } else {
                        break;
                    };

                    printf("Element yg dihapus : %d\n", pilihan);
                    PrintQueueInfo(Q);

                    if (IsQueuekEmpty(Q)){
                        printf("Tekan apa saja..");
                        getchar();
                        getchar();
                        break;
                    };


                };
            break;

            case 3:
                printf("\n");
                PrintQueueInfo(Q);
                printf("Tekan apa saja...");
                getchar();
                getchar();
                break;
            break;
            
            default:
                
            break;
            
            case 0:

            break;
        }
        
    } while (pilihan != 0);
};