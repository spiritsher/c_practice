#include <stdio.h>  
typedef int (*R)[2];


#define ROW 3 
#define COL 2

R fun(int a[6])  
{  
    int i,j;
    R arr2D;

    for (i = 0; i < 3; i++)
    {
        for(j=0;j<2;j++)
        {
         arr2D[i][j]=a[i*COL+j];
        }
    }
    return arr2D;  
}  
int main()  
{  

    int a[]  = {1,2,3,4,5,6};

    int i,j;  
    // int a[2][2] = {1,2,5,6};  
    R c;  
    c = fun(a);   
    for(i=0;i<3;i++) 
    {
        for(j=0;j<2;j++)  {
            printf("%d ",c[i][j]);  
        }
            printf("\n");   
    } 
 

    return 0;  
}  