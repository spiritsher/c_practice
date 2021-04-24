#include <stdio.h>
#include <math.h>

int mystery(int , int );
int foobar(int* n);

int main(void)
{

    // int i = 0, j = 1, k = 3;
    // printf("the result is: %d\n", mystery(7,91));
    // return 0;

 char * str;
 char a[5] = "abcd";
* str = & a;
    int k = 6;
// printf("foobar(k) = %d,",foobar(&k) );
printf(" k = %s\n",  *str);
}

int mystery(int p, int q)
{
     
    int r;
    if ((r = p % q) == 0)
        return q; 
    else return mystery(q, r);
}

int foobar(int* n){
     *n = *n +1;
     return *n;
}