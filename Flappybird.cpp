
#include "TXLib.h"

struct Plane
    {
    int x, y;

    int v;
    };


void Plane ();

int GetPixelVOL (struct Plane Pl, int VOLX, HDC Backcolor);

int main()
    {
    txCreateWindow (1024, 576);

    Plane ();

    return 0;
    }

void Plane ()
    {


    HDC Plane = txLoadImage ("����.bmp");
    if (Plane == NULL) txMessageBox ("������ ������");

    HDC BackG = txLoadImage ("������.bmp");
    if (BackG == NULL) txMessageBox ("� ���� �����������");

    HDC BackColor = txLoadImage ("KJ{JDYZ.bmp");
    if (BackColor == NULL) txMessageBox ("����� ������� ����������");

    int BackGX = txGetExtentX (BackG) / 10;

    struct Plane Pl {400, 100, 0};

    int VOLX = 0;

    int Speed = 10;

    while (1 < 2)
        {

        txBitBlt (txDC(), 0, 0, BackGX, 0, BackG, VOLX);

        int ResaultPetya = GetPixelVOL (Pl, VOLX, BackColor);  //txGetPixel (Pl.x + 152 + VOLX, Pl.y - Pl.v, BackColor);

        //if (ResaultPetya == 1) VOLX = 0;

        txAlphaBlend (txDC (), Pl.x, Pl.y - Pl.v, 0, 0, Plane);

        printf ("� ���� �������� %d\n", ResaultPetya);

        VOLX += Speed;

        Pl.y += 10;

       // PlaneX += 5;

        txSleep (50);

        if (GetAsyncKeyState (VK_SPACE)) Pl.v = Pl.v + 20;

        if (VOLX >= 9216) VOLX = 0, Speed = 15;

        }
    }

int GetPixelVOL (struct Plane Pl, int VOLX, HDC BackColor)
    {
    COLORREF Color1 = txGetPixel (Pl.x + 152 + VOLX, Pl.y - Pl.v, BackColor);
    COLORREF Color2 = txGetPixel (Pl.x +       VOLX, Pl.y - Pl.v, BackColor);
    COLORREF Color3 = txGetPixel (Pl.x +  76 + VOLX, Pl.y - Pl.v, BackColor);
    COLORREF Color4 = txGetPixel (Pl.x + 152 + VOLX, Pl.y - Pl.v + 57, BackColor);
    COLORREF Color5 = txGetPixel (Pl.x +       VOLX, Pl.y - Pl.v + 57, BackColor);
    COLORREF Color6 = txGetPixel (Pl.x +  76 + VOLX, Pl.y - Pl.v + 57, BackColor);

    int ResaultVasya = 0;

    if (Color1 == RGB (255, 0, 0) || Color2 == RGB (255, 0, 0) || Color3 == RGB (255, 0, 0) ||
        Color4 == RGB (255, 0, 0) || Color5 == RGB (255, 0, 0) || Color6 == RGB (255, 0, 0)) ResaultVasya = 1;

    return ResaultVasya;
    //txGetPixel (Pl.x + 152 + VOLX, Pl.y - Pl.v, BackColor);
    //txGetPixel (Pl.x + 152 + VOLX, Pl.y - Pl.v, BackColor);
    //txGetPixel (Pl.x + 152 + VOLX, Pl.y - Pl.v, BackColor);
    //txGetPixel (Pl.x + 152 + VOLX, Pl.y - Pl.v, BackColor);
    }


