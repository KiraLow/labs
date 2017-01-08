#include "qdbmp.h"
#include <stdio.h>
#include <math.h>


int main(void)
{
    BMP*    bmp;
    UCHAR   r1,r2,r3,r4,r5,r6,r7,r8,r9, g,g1,g2,g3,g4,g5,g6,g7,g8,g9;
    UCHAR   b1, b2, b3, b4, b5, b6, b7, b8, b9;
    UINT    width, height;
    UINT    x, y;
    int Gred, Ggreen, Gblue;

    bmp = BMP_ReadFile("/home/vlad/Prg/semesrovye/img/sobel/ansi/lena.bmp");    BMP_CHECK_ERROR( stderr, -1 ); /* If an error has occurred, notify and exit */

    width = BMP_GetWidth( bmp );
    height = BMP_GetHeight( bmp );
    for ( x = 0 ; x < width-2 ; ++x ) {
        for ( y = 0 ; y < height-2 ; ++y ) {
            BMP_GetPixelRGB(bmp, x, y, &r1, &g1, &b1);
            BMP_GetPixelRGB(bmp, x - 1, y, &r2, &g2, &b2);
            BMP_GetPixelRGB(bmp, x + 1, y, &r3, &g3, &b3);
            BMP_GetPixelRGB(bmp, x - 1, y - 1, &r4, &g4, &b4);
            BMP_GetPixelRGB(bmp, x, y - 1, &r5, &g5, &b5);
            BMP_GetPixelRGB(bmp, x + 1, y, &r6, &g6, &b6);
            BMP_GetPixelRGB(bmp, x - 1, y + 1, &r7, &g7, &b7);
            BMP_GetPixelRGB(bmp, x, y + 1, &r8, &g8, &b8);
            BMP_GetPixelRGB(bmp, x + 1, y + 1, &r9, &g9, &b9);
            
            Gred = (r1 + r2 + r3 + r4 + r5 + r6 + r7 + r8 + r9) / 9;
            Ggreen = (g1 + g2 + g3 + g4 + g5 + g6 + g7 + g8 + g9) / 9;
            Gblue = (b1 + b2 + b3 + b4 + b5 + b6 + b7 + b8 + b9) / 9;
            

            BMP_SetPixelRGB( bmp, x, y, Gred, Ggreen, Gblue);

        }
    }

    BMP_WriteFile( bmp, "/home/vlad/Prg/semesrovye/img/imgGauss/ansi/output.bmp");
    BMP_CHECK_ERROR( stderr, -2 );

    BMP_Free( bmp );

    return 0;
}


