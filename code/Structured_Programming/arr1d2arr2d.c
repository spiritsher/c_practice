#include <stdio.h>
#include <stdlib.h>

#define ROW 2
#define COL 2

// int main(int argc, char *argv[])
// {
//     int arr1D[]  = {1,2,3,4,5,6};
//     int arr2D[ROW][COL];
//     int i,j;
//     //一维维整型数组转换为二维整型数组
//     for(i=0;i<ROW;i++)
//     {
//         for(j=0;j<2;j++)
//         {
//          arr2D[i][j]=arr1D[i*COL+j];
//         }
//     }
//     //二维整型数组打印显示
//         for(i=0;i<ROW;i++)
//     {
//         for(j=0;j<COL;j++)
//         {
//           printf("%d  ", arr2D[i][j]);
//         }
//          printf("\n");
//     }
//     // system("pause");
//     return 0;
// }

typedef int (*R)[2];
R fun(int b[][2])
{
    R e;
    int i, j;
        int d[4] = {1, 2, 5, 6};

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            e[i][j] = d[1];
        }
    }
    return e;
}
int main()
{
    int i, j;
    int a[4] = {1, 2, 5, 6};
    int b[2][2] = {0};  

    R c;
    c = fun(b);
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            printf("%d ", c[i][j]);
    return 0;
}