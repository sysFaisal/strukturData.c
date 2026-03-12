#include "boolean.h"
#include "point.h"
#include <math.h>
#include <stdio.h>

//Absis X
//Ordinat Y

void CreatePOINT (POINT *p){
    p->x = 0;
    p->y = 0;
};

void CreatePOINT2 (POINT *p, int XBaru, int YBaru){
    p->x = XBaru;
    p->y = YBaru;
};

int GetAbsis(POINT p){
    return p.x;
};

int GetOrdinat(POINT p){
    return p.y;
};

void SetAbsis(POINT *p, int newX){
    p->x = newX;
};

void SetOrdinat(POINT *p, int newY){
    p->y = newY;
};

void BacaPOINT(POINT *p){
    int x = 0, y = 0;

   printf("Masukan X : "); 
   scanf("%d", &x);
   SetAbsis(p, x);

   printf("Masukan Y : ");
   scanf("%d", &y);
   SetOrdinat(p, y);

};

void CetakPOINT(POINT p){
    printf("(X:%d , y:%d)",p.x, p.y);
};

boolean EQ (POINT p1, POINT p2){
    if ((GetAbsis(p1) == GetAbsis(p2)) && (GetOrdinat(p1) == GetOrdinat(p2))){
        return (true);
    }
    return (false);
}

boolean NEQ (POINT p1, POINT p2){
    return (!EQ(p1, p2));
}

boolean LT (POINT p1, POINT p2){
    if ((GetAbsis(p1)) < (GetAbsis(p2))){
        return (true);

    } else if 
        ((GetAbsis(p1) == GetAbsis(p2) && GetOrdinat(p1) < GetOrdinat(p2))){
        return (true);

    } else {
        return (false);
    }

} 

boolean MT (POINT p1, POINT p2){
    if ((GetAbsis(p1)) > (GetAbsis(p2))){
        return (true);
        
    } else if 
        ((GetAbsis(p1) == GetAbsis(p2) && GetOrdinat(p1) > GetOrdinat(p2))){
        return (true);

    } else {
        return (false);
    }
}

boolean IsOrigin(POINT p){
    if (GetAbsis(p) == 0 && GetOrdinat(p) == 0){
        return (true);
    }
    return false;
};

boolean IsOnSbx(POINT p){
    if (GetOrdinat(p) == 0){
        return (true);
    }
    return false;
};

boolean IsOnSby(POINT p){
    if (GetAbsis(p) == 0){
        return (true);
    }
    return false;
};

int Kuadran(POINT p) {
    
    if (GetAbsis(p) > 0 && GetOrdinat(p) > 0) {
        return 1;
    } 
    else if (GetAbsis(p) < 0 && GetOrdinat(p) > 0) {
        return 2;
    } 
    else if (GetAbsis(p) < 0 && GetOrdinat(p) < 0) {
        return 3;
    } 
    else { 
        return 4; 
    }

};

POINT MirrorOf(POINT p, boolean Sbx, boolean Sby){
    POINT pnew;
    float x = p.x;
    float y = p.y;

    if (Sbx == true){
        y = (y * -1);
    };

    if (Sby == true){
        x = (x * -1);
    };

    CreatePOINT2(&pnew, x, y);

    return pnew;
};

float Jarak0(POINT p){
    float dx = GetAbsis(p); 
    float dy = GetOrdinat(p);

    return sqrt((pow(dx,2)) + (pow(dy,2)));
};

void GeserKeSbX (POINT *p){
    SetOrdinat(p,0);
};

void GeserKeSbY (POINT *p){
    SetAbsis(p,0);
};