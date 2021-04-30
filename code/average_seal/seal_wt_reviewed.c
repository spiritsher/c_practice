#include <stdio.h>

//Declare function for calculating average of data.
float average_of_data(int size_of_array, int elephant_seal_data[]);

int main()
{    
    FILE *fptr;
    fptr=fopen("elephant_seal_data.txt", "r"); //To open elephant_seal_data.txt file
    int elephant_seal_data[1000]; //Number of elements given in elephant_seal_data.txt is 1000.
    float average;
    for(int i=0; i<1000; i++)
    {
        fscanf(fptr, "%d", &elephant_seal_data[i]);
    }

    // To calculate average. We will call function float average_of_data(int size_of_array, int elephant_seal_data[]);
    average = average_of_data(1000, elephant_seal_data); //We will pass size of array [1000] and the array.
    
    printf("\nThe average of elephant seal weight is = %f\n\n", average);

    return 0;
}

//Create function for calculating average of data.
float average_of_data(int size_of_array, int elephant_seal_data[])
{
    float average, sum;

    for(int i=0 ; i<size_of_array ; i++)
    {
        sum = sum + elephant_seal_data[i];
    }
    average=sum/size_of_array;

    return average;
}