/* Option 2 (Natural or Social Science Focus)
1. Open and read a file of integer pairs into an array that is created with the first integer telling you how many to read. 
2. Each pair will be a stuct rational -meaning it represents a rational number. So a struct will have two members—the numerator and the denominator.

eg:
So 2  9  11  4  5  would mean create an rational  array size 2 and read in the remaining 4 values into data[].   
Data[0] will be (9,11)  - the rational 9/11. Data[1] will be (4, 5)—the rational 4/5.

Write four  routines to add rationals, multiply rationals, subtract rationals and divide rationals.  
Take the file posted with this homework and  produce the sum of all the rationals and the average of all the rationals in the file. 

solution:
1. struct type define ranumber;
2. Creating rules for rational number operations;
3. get data from data.text, and put data into array;
4. molecule: arr[2i+1]; denominator:arr[2i+2];
5. ranumber calculation;
6. print out result to data1.txt
*/

#include <stdio.h>

typedef struct
{
	int molecule;
	int denominator;
} ranumber;

ranumber ranum[2];


void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int reduction(int x, int y)
{
	int z;
	if (x < y)
		swap(&x, &y);
	z = y;
	while (x % y != 0)
	{
		z = x % y;
		x = y;
		y = z;
	}
	return z;
}

void simple(ranumber *c)
{
	int d = reduction(c->molecule, c->denominator);
	c->molecule /= d;
	c->denominator /= d;
}

ranumber add(ranumber a, ranumber b)
{
	ranumber c = {a.molecule * b.denominator + a.denominator * b.molecule, a.denominator * b.denominator};
	simple(&c);
	return c;
}

ranumber minus(ranumber a, ranumber b)
{
	ranumber c = {a.molecule * b.denominator - a.denominator * b.molecule, a.denominator * b.denominator};
	simple(&c);
	return c;
}

ranumber multiple(ranumber a, ranumber b)
{
	ranumber c = {a.molecule * b.molecule, a.denominator * b.denominator};
	simple(&c);
	return c;
}

ranumber divide(ranumber a, ranumber b)
{
	ranumber c = {a.molecule * b.denominator, a.denominator * b.molecule};
	simple(&c);
	return c;
}

int readfile(char *file,  int* arr1d)
{
	int a[5];
	int i;
	FILE *fp = fopen(file, "r");
	if (fp == NULL)
	{
		printf("invalid file.\n");
		return -1;
	}
	for (i = 0; !feof(fp); i++)
	{
	fscanf(fp, "%d", (arr1d+i) );
	// arr1d[i] = a[i];
	}

	fclose(fp);

	if (i % 2 != 0)
	{
		printf("invalid data input of %s file", file);
		return -1;
	}

	return 1;
}



int main()
{
	int i,j,c;
	char *file_name = "data.txt";
	int arr_1d[5];
	int row = 0;
	int line = 0;

	ranumber ranum_result;

	c = readfile(file_name, &arr_1d);

	for(i=0; i<5; i++)
	{
			printf("%d ", *(arr_1d+i));
	}

	int total = arr_1d[0];
	 row = arr_1d[0]/ 2;

	 for (i = 0; i < row; i++)
	 {
		ranum[i].molecule = arr_1d[2*i + 1];
		ranum[i].denominator = arr_1d[2*i + 2];
		printf("ranum %d molecule is: %d, denominator is %d.\n",i, ranum[i].molecule, ranum[i].denominator);

	 }
	
	    FILE *fp2= fopen ("data1.txt","w");


	 	ranum_result = add(ranum[0], ranum[1]);
		fprintf(fp2,"after add calculation result.molecule is: %d, result.denominator is %d.\n", ranum_result.molecule, ranum_result.denominator);

		ranum_result = minus(ranum[0], ranum[1]);
		fprintf(fp2,"after minus calculation result.molecule is: %d, result.denominator is %d.\n", ranum_result.molecule, ranum_result.denominator);

		ranum_result=multiple(ranum[0], ranum[1]);
		fprintf(fp2, "after multiple calculation result.molecule is: %d, result.denominator is %d.\n", ranum_result.molecule, ranum_result.denominator);

		ranum_result=divide(ranum[0], ranum[1]);
		fprintf(fp2, "after divide calculation result.molecule is: %d, result.denominator is %d.\n", ranum_result.molecule, ranum_result.denominator);

		fprintf(fp2,"\n+++++++++++++++++++\n");
		
		fclose (fp2); 

		 return 0;
}