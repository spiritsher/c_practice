#include <stdio.h>


void print_grades(int how_many, int arr[]);
double average_grade(int how_many, int arr[]);




int main(void)
{
    // const int SIZE =5;
    // int grades[SIZE] ={78,67,92,83,88};

    int SIZE;
    int i;

    double average;

    printf("please input the size of array：\n");
    scanf("%d", &SIZE);

    int grades[SIZE];

    printf("please input the array：\n");
    for (i=0; i<SIZE; i++){
        scanf("%d", &grades[i]);
    }
    


    print_grades(SIZE, grades);
    average = average_grade(SIZE,grades);
    printf("my average is %f", average);

    return 0;
    }



double average_grade(int how_many, int grades[])
{
    int i;
    double sum =0;

    for (i=0; i<how_many; i++){
        sum+=grades[i];
    }
    return (sum/how_many);
}

void print_grades(int how_many, int grades[])
{
    int i;

    printf("I have %d grades\n", how_many);
    for(i=0;i<how_many;i++)
    printf("%d\t", grades[i]);
}
