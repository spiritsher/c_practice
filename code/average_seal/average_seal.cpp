/* calculate the average weight of seal-elephant
Roadmap:
1. copy elephant_data to "data.txt" file;
2. save the file in the save folder with src.
3. compiling src: gcc average_seal.cpp gcc -o average_seal.out -g
4. run the binary file with argv: ./average_seal.out -data.txt

result:
print the input array.
calculate the average with solution 1#,
counter the total index, counter the sum weight;
calculate the average with solution 2#,
average = sum/counter

solution 1#: to avoid overflow for int.
use following solution to calculate average:  
average = average+(input_arr[i]-average)/++counter
calculate average for every input elements.

sjw.spirit@gmail.com
23.04.2021 */

#include <stdio.h>
#include <stdlib.h>

int get_data(const char* argv, int *p);


int main(int argc, char* argv[])
{
        const int MAX = 2048;
        int input_arr[MAX];
        int n;
        int i,j;
        int sum;
        double average,average_1;

        if (argc != 2)
        {
                return 1;
        }

        FILE *inputFile = fopen(argv[1], "r");

        if (inputFile == NULL)
        {
                printf("Error1\n");
                return 1;
        }

        while (fscanf(inputFile, " %d", &n) == 1) 
        {

                input_arr[i]=n;
                sum = sum+input_arr[i];
                printf("%d\n",input_arr[i]);
                average = average+(input_arr[i]-average)/++i;
        }

                printf("average weight of seal is %lf\n",average);

                average_1 = (double)sum/i;

        if(!feof(inputFile)){
                printf("error");
                return 1;
        }

        printf("%d\n",i);
        printf("another calculation: sum is %d, average weight of seal is %.6f\n",sum, average_1);

        fclose(inputFile);
        return 0;

 }

