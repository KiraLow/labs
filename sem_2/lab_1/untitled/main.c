#include "qdbmp.h"
#include <math.h>
#include <stdio.h>

int main(void)
{
    BMP* bmp;
    UCHAR r,r1,r2,r3,r4,r5,r6,r7,r8,g,g1,g2,g3,g4,g5,g6,g7,g8,b,b1,b2,b3,b4,b5,b6,b7,b8;
    UINT width, height;
    UINT x, y;
    int R,G,B;

    bmp = BMP_ReadFile("/home/Prg/sem_2/lab_1/lena.bmp" );
    BMP_CHECK_ERROR( stderr, -1 );

    width = BMP_GetWidth( bmp );
    height = BMP_GetHeight( bmp );

    for (x = 0; x < width - 2; ++x)
    {
        for (y = 0; y < height - 2; ++y)
        {
            BMP_GetPixelRGB(bmp, x, y, &r, &g, &b);
            BMP_GetPixelRGB(bmp, x - 1, y, &r1, &g1, &b1);
            BMP_GetPixelRGB(bmp, x + 1, y, &r2, &g2, &b2);
            BMP_GetPixelRGB(bmp, x - 1, y - 1, &r3, &g3, &b3);
            BMP_GetPixelRGB(bmp, x, y - 1, &r4, &g4, &b4);
            BMP_GetPixelRGB(bmp, x + 1, y, &r5, &g5, &b5);
            BMP_GetPixelRGB(bmp, x - 1, y + 1, &r6, &g6, &b6);
            BMP_GetPixelRGB(bmp, x, y + 1, &r7, &g7, &b7);
            BMP_GetPixelRGB(bmp, x + 1, y + 1, &r8, &g8, &b8);
            R = (r+r1+r2+r3+r4+r5+r6+r7+r8)/10;
            G = (g+g1+g2+g3+g4+g5+g6+g7+g8)/10;
            B = (b+b1+b2+b3+b4+b5+b6+b7+b8)/10;

            BMP_SetPixelRGB( bmp, x, y, R, G, B);

        }

    }

    BMP_WriteFile( bmp, ("/home/Prg/sem_2/lab_1/output.bmp"));
    BMP_CHECK_ERROR( stderr, -2 );

    BMP_Free( bmp );

    return 0;
}