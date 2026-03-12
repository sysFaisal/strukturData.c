#include <stdio.h>
#include "point.h"

#include <stdio.h>
#include "point.h"

int main() {
    POINT P1, P2, P3;

    printf("======================================\n");
    printf("        PROGRAM TESTING POINT         \n");
    printf("======================================\n\n");

    printf("--- TEST 1: BACA DAN CETAK TITIK ---\n");
    printf("Silakan masukkan data untuk Titik 1 (P1)\n");
    BacaPOINT(&P1);
    
    printf("\nSilakan masukkan data untuk Titik 2 (P2)\n");
    BacaPOINT(&P2);

    printf("\nData yang Anda masukkan:\n");
    printf("P1 = "); CetakPOINT(P1); printf("\n");
    printf("P2 = "); CetakPOINT(P2); printf("\n\n");

    
    printf("--- TEST 2: PERBANDINGAN P1 & P2 ---\n");
    if (EQ(P1, P2)) {
        printf("- P1 SAMA DENGAN P2\n");
    }
    if (NEQ(P1, P2)) {
        printf("- P1 TIDAK SAMA DENGAN P2\n");
    }
    if (LT(P1, P2)) {
        printf("- P1 LEBIH KECIL dari P2\n");
    }
    if (MT(P1, P2)) {
        printf("- P1 LEBIH BESAR dari P2\n");
    }
    printf("\n");

    
    printf("--- TEST 3: POSISI P1 ---\n");
    if (IsOrigin(P1)) {
        printf("- P1 berada tepat di Titik Origin (0,0)\n");
    } else if (IsOnSbx(P1)) {
        printf("- P1 berada di atas Sumbu X\n");
    } else if (IsOnSby(P1)) {
        printf("- P1 berada di atas Sumbu Y\n");
    } else {
        printf("- P1 berada di Kuadran %d\n", Kuadran(P1));
    }
    printf("\n");

    
    printf("--- TEST 4: JARAK KE PUSAT ---\n");
    printf("- Jarak P1 ke origin (0,0) adalah: %.2f\n\n", Jarak0(P1));

    
    printf("--- TEST 5: PENCERMINAN P1 ---\n");
    P3 = MirrorOf(P1, true, false); 
    printf("- P1 dicerminkan terhadap Sumbu X menjadi: ");
    CetakPOINT(P3); 
    printf("\n\n");

    
    printf("--- TEST 6: PERGESERAN P1 ---\n");
    GeserKeSbX(&P1);
    printf("- P1 setelah dipaksa geser ke Sumbu X (Y jadi 0): ");
    CetakPOINT(P1);
    printf("\n");

    printf("\n======================================\n");
    printf("          TESTING SELESAI             \n");
    printf("======================================\n");

    getchar();
    getchar();
    return 0;
}