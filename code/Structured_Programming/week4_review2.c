/*Option 1 (General)*/

/*This program can help to open and read a file of integers into an array, 
and then compute their average as a double and their max as an int.*/

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

void read_data(FILE *ptr, int data[], int *size){	//This function can help to read in the data and store them in an array.
	int temp;
	int i;
	
	fscanf(ptr, "%d", size);	//get the size of data
	for(i = 0; i < *size; i ++){	
		fscanf(ptr, "%d", &temp);	//read in and store the data
		data[i] = temp;
	}	
}

double average(int data[], int size){	//calculate the average value of data
	double ave;
	int i;
	
	ave = 0.0;
	for(i = 0; i < size; i ++){
		ave += data[i];
	}
	ave /= size;	//get the average value
	
	return ave;
}

int max(int data[], int size){	//calculate the max value of data
	int max_value;
	int i;
	
	max_value = data[0];
	for(i = 1; i < size; i ++){
		if(data[i] > max_value){
			max_value = data[i];	//get the max value
		}
	}
	return max_value;
}

void print_info(double ave, int max){	//print out the average and max value of data to the screen
	printf("The average value is : %.2lf\n", ave);
	printf("The max value is : %d\n", max);
}

void output_data(FILE *ptr1, double ave, int max){	//print the information to an output file named 'answer-hw3'
	fprintf(ptr1, "The average value is : %.2lf\n", ave);
	fprintf(ptr1, "The max value is : %d\n", max);
}

int main(void){
	FILE *ptr;
	FILE *ptr1;
	int data[MAX_SIZE];
	double ave;
	int max_value;
	int size;
	char filename[20];
	
	printf("This program can help to calculates average and max value of the data from a file.\n");
	printf("Please enter the file name : ");
	scanf("%s", &filename);	//get the filename from user
	
	ptr = fopen(filename, "r");	//read the file
	ptr1 = fopen("answer-hw3.txt", "w");	//open for write
	
	read_data(ptr, data, &size);	//read in the data
	ave = average(data, size);		//calculate the average value
	max_value = max(data, size);	//calculate the max value
	print_info(ave, max_value);		//print out the information to the screen
	output_data(ptr1, ave, max_value);	//output the information into 'answer-hw3'
	
	fclose(ptr);
	fclose(ptr1);
	return 0;
}



