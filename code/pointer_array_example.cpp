#include <stdio.h>

int * get_array();

int main(void)
{
    // const int SIZE =5;
    // int grades[SIZE] ={78,67,92,83,88};
    int *p;
    int length = 0;
    int i;

    p = get_array();
    while (*p)
    {
        printf("the element %d is %d.\n", length++, *p);
        p++;
    }


    return 0;
}
    
int * get_array()
{
    int SIZE;
    int i,j;

    printf("please input the size of array：\n");
    scanf("%d", &SIZE);

    int arr[SIZE];
    int * want = arr;

    printf("please input the array：\n");
    for (i=0; i<SIZE; i++){
        scanf("%d", &arr[i]);
    }
    
    // printf("\n+++++++++++\n");


    // for (j=0; j<SIZE; j++){
    //     printf("%d, ", arr[j]);
    // }

    // printf("\n+++++++++++\n");

    return want;
}