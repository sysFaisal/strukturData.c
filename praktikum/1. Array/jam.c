#include <stdio.h>
#include "jam.h"


void CreateJam(Jam *J, int HH, int MM, int SS) {
    J->Hour = HH;
    J->Minute = MM;
    J->Second = SS;
};

int GetHour(Jam J){
    return J.Hour;
};

int GetMinute(Jam J){
    return J.Minute;
};

int GetSecond(Jam J){
    return J.Second;
};

void setHour(Jam *J, int setHour ){
    J->Hour = setHour;
};

void setMinute(Jam *J, int setMinute){
    J->Minute = setMinute;
};

void setSecond(Jam *J, int setSecond){
    J->Second = setSecond;
};

void ReadJam(Jam *J){
    int HH = 0;
    int MM = 0;
    int SS = 0;
    do {  
        printf("Masukan Jam : "); scanf("%d", &HH);
        printf("Masukan Menit : "); scanf("%d", &MM);
        printf("Masukan Detik : "); scanf("%d", &SS);   
    } while (HH < 0 || HH > 23 || MM <0 || MM> 59 || SS <0 || SS> 59);
    CreateJam(J, HH, MM, SS);
};

void PrintJam(Jam J){
    printf("%d:%d:%d\n",J.Hour,J.Minute,J.Second);
};

boolean isValid(int HH, int MM, int SS){
    if (HH>=0 && HH<=23 && MM>=0 && MM<=59 && SS>=0 && SS<=59){
        return (true);
    } else {
        return (false);
    }
};

boolean JEQ(Jam J1, Jam J2) {
    if (J1.Hour == J2.Hour && J1.Minute == J2.Minute && J1.Second == J2.Second){
        return (true);
    } else {
        return (false);
    }
}

boolean JLT(Jam J1, Jam J2) {
    if (J1.Hour < J2.Hour || J1.Minute < J2.Minute || J1.Second < J2.Second){
        return (true);
    } else {
        return (false);
    }
}

boolean JGT(Jam J1, Jam J2) {
    if (J1.Hour > J2.Hour || J1.Minute > J2.Minute || J1.Second > J2.Second){
        return (true);
    } else {
        return (false);
    }
}

void Reset (Jam *J){
    J->Hour = 0;
    J->Minute = 0;
    J->Second = 0;
};

Jam NextDetik(Jam J){
    Jam jamBaru;

    jamBaru.Hour = J.Hour;
    jamBaru.Minute = J.Minute;
    jamBaru.Second = J.Second + 1;
    jamBaru = J;
    jamBaru.Second = jamBaru.Second + 1;

    if (jamBaru.Second > 59) {
        jamBaru.Second = 0;
        jamBaru.Minute = jamBaru.Minute + 1;
        if (jamBaru.Minute > 59) {
            jamBaru.Minute = 0;
            jamBaru.Hour = jamBaru.Hour + 1;
            if(jamBaru.Hour > 23){
                jamBaru.Hour = 0;
            }
        }
    }

    return (jamBaru);
};

Jam NextNDetik(Jam J, int N){
    int i;
    Jam jamBaru;
    jamBaru = J;

    if (N > 0 && N <= 86400) { // menambahkan detik hanya sampai 24 jam
        for (i=1; i<=N; i++){
            jamBaru = NextDetik (jamBaru);
        }
    }
    return (jamBaru);
};

long int JamToDetik (Jam J) {
    long int detik;
    detik = (J.Hour * 3600) + (J.Minute * 60) + J.Second;
    return (detik);
};

long int Durasi(Jam Jaw, Jam Jakh){
    long int detikAwl, detikAkh, result;

    detikAwl = JamToDetik(Jaw);
    detikAkh = JamToDetik(Jakh);
    result = detikAwl - detikAkh;
    if (result < 0) {
        result = result * (-1);
    }
    return (result);
};
