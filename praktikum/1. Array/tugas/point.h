typedef struct{
    int x;
    int y;
}POINT;

void CreatePOINT (POINT *p);
void CreatePOINT2 (POINT *p, int XBaru, int YBaru);

int GetAbsis(POINT p);
int GetOrdinat(POINT p);

void SetAbsis(POINT *p);
void SetOrdinat(POINT *p);

void BacaPOINT(POINT *p);
void CetakPOINT(POINT p);

boolean IsOrigin(POINT p);
boolean IsOnSbx(POINT p);
boolean IsOnSby(POINT p);
int Kuadran(POINT p);

POINT MirrorOf(POINT p, boolean Sbx, boolean Sby);
float Jarak0(POINT p);
void GeserKeSbX (POINT *p);
void GeserKeSbY (POINT *p);