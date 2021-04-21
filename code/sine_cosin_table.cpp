/* 
C program to output table for sin(x) cos(x)
Deg2Rad fomular: rad = deg *(3.142/180.0).
AuthorAuthor: Jiawei.SHE
E_mail:sjw.spirit@gmail.com
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159

float cal_sine(float deg);
float cal_cosine(float deg);

int main ()
{
    int deg;
    float sinx, cosinx;

    printf("- - - - - - - - - - - - - - - - - -");
    printf("\nAngle \t Sin \t Cosin \t");
    printf("- - - - - - - - - - - - - - - - - -");

    for (deg=0; deg<=180; ++deg)
    {
        sinx=cal_sine(deg);
        cosinx=cal_cosine(deg);
        printf("\n%3d \t %lf \t %lf\n", deg, sinx, cosinx);
    } 
    return 0;
}

float cal_sine(float deg)
{
    float sin_val;
    float Rad;
    Rad = deg *(PI/180.0);
    sin_val = sin(Rad);
    return sin_val;
}

float cal_cosine(float deg)
{
    float cosin_val;
    float Rad;
    Rad = deg *(PI/180.0);
    cosin_val = cos(Rad);
    return cosin_val;
}

