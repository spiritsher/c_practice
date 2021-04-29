#include<stdio.h>
#include<math.h> /* has  sin(), abs(), and fabs() */
int main(void)
{ 
    double interval;
    int i;
    for(i = 0; i <30; i++)
    {
        interval = i/10.0;
        double v_abs=fabs(sin(interval));
        printf("sin( %lf ) = %lf \t", interval, v_abs);
    }
    printf("\n+++++++\n");
    return 0;
}
