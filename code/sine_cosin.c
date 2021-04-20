/* 
C program to calculate value of sin(x)
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
    float deg;
    float sinx, cosinx;

    printf("Enter deg (0-360)\n");
    scanf("%f", &deg);
    sinx=cal_sine(deg);
    cosinx=cal_cosine(deg);
    printf("The result of calculating the Sine of %f degrees is %f.\n", deg, sinx);
    printf("The result of calculating the cosin of %f degrees is %f.\n", deg, cosinx);
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

