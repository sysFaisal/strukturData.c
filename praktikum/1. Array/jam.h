#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"

typedef struct{
    int Hour;
    int Minute;
    int Second;
}Jam;

void CreateJam(Jam *J, int HH, int MM, int SS);

int GetHour(Jam J);
int GetMinute(Jam J);
int GetSecond(Jam J);

void setHour(Jam *J, int setHour );
void setMinute(Jam *J, int setMinute);
void setSecond(Jam *J, int setSecond);

void ReadJam(Jam *J);
void PrintJam(Jam J);

boolean isValid(int HH, int MM, int SS);

boolean JEQ(Jam J1, Jam J2);
boolean JLT(Jam J1, Jam J2);
boolean JGT(Jam J1, Jam J2);

void Reset (Jam *J);

Jam NextDetik (Jam J);
Jam NextNDetik(Jam J, int N);

long int JamToDetik (Jam J);
long int Durasi(Jam Jaw, Jam Jakh);