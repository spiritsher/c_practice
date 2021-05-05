# include <stdio.h>
int main(void)
{   
    int a = 10;
    const int *p = &a;
    int * q = &a;
        //*p = 30; 

    *q = 20;
    printf("a = %d\n", a);
    a = 30;
    printf("a = %d\n", a);
    return 0;
}