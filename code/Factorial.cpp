/* Recursive v. Iterative Factorial
simple recursion
sjw.spirit@gmail.com 22.04.2021
n!=1*2*3*...*n */

#include <stdio.h>

long int factorial(int n);
long int recursive_factorial(int n);

int main() 
{
    int n=0;
    int i,j;
    printf("Enter a positive integer: ");
    scanf("%d",&n);
    printf("Factorial of %d = %ld\n", n, factorial(n));
    printf("\n\n");
    printf("Factorial of %d = %ld\n", n, recursive_factorial(n));
    return 0;
}

#include<stdio.h>
/* long allows it to work for upto 20 */
long int factorial (int n)
{
    long f =1;
    int i;

    for (i=1; i<=n; i++){
        f=f*i;
    }
    return f;
}

long int recursive_factorial(int n) 
{
    if (n==1)
        return 1;
    else
        return (n*recursive_factorial(n-1));
}



