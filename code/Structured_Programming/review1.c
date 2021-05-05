/* General */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void read_file(FILE *ifp, int d[], int size){
	
    int i; 
    for(i = 0; i < size; i++){
        fscanf(ifp, "%d", &d[i]);
    }
}

double average(int d[], int size){
	double avg;
	int i;
	for(i = 0; i < size; i++){
		avg += d[i];
	}
	return (avg/size);
}

int find_max(int d[], int size){
    if(size < 1){
        perror("No data");
        exit(1);
    }

    int i, max = d[0];
    for(i = 1; i < size; i++){
        if(d[i] >  max)
            max = d[i];
    }
    return max;
}

void store_answer(int d[], int size, double avg, int max, FILE *ofp){
    
    char line1[] = "File contained following elements:\n";
    char maximum[] = "Max is:\t";
    char average[] = "Average is:\t";
    char element[10];
    int i, j;
    for(i = 0; i < strlen(line1); i++){
        putc(line1[i], ofp);
    }


    for(i = 0; i < size; i++){
        sprintf(element, "%d", d[i]);
        for(j = 0; j < strlen(element); j++){
            putc(element[j], ofp);
        }
        putc('\t', ofp);
        if((i+1)%10 == 0)
            putc('\n', ofp);

    }
    putc('\n', ofp);
    putc('\n', ofp);
    for(i = 0; i < strlen(maximum); i++){
        putc(maximum[i], ofp);
    }
    sprintf(element, "%d", max); // Converting max value to string
    for (i = 0; i < strlen(element); i++){
        putc(element[i], ofp);
    }
    putc('\n', ofp);
    putc('\n', ofp);
    for(i = 0; i < strlen(average); i++){
        putc(average[i], ofp);
    }
    sprintf(element, "%lf", avg); // Converting avg value to string
    for(i = 0; i < strlen(element); i++){
        putc(element[i], ofp);
    }
    putc('\n', ofp);
    putc('\n', ofp);
}

void print_file(FILE *fp){
	rewind(fp); 
	char c;
	while((c = getc(fp)) != EOF){
		putc(c, stdout);
	}
}

int main(int argc, char *argv[]){
    FILE *ifp, *ofp; 
    int n, max;
    double avg;
    if(argc != 2){
        printf("Wrong number of arguments, please specify only input file name\n");
        exit(1);
    }
    ifp = fopen(argv[1], "r");
    ofp = fopen("answer-hw3", "w+");
    if(fscanf(ifp, "%d", &n) != 1){
        printf("File empty\n");
        exit(1);
    }
    int data[n];
    read_file(ifp, data, n);
    avg = average(data, n);
    max = find_max(data, n);
    store_answer(data, n, avg, max, ofp);
    print_file(ofp);
    fclose(ifp);
    fclose(ofp);
}