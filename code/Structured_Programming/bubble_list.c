/* bubble_sorted_list
RAQ:

1. generate a randomly generated set of 100 integers.  
1. Use the linear linked list code to store .
3. write a routine that will rearrange the list in sorted order of these values. 

Note you might want to use bubble sort to do this. Print these values in rows of 5 on the screen.
How will this work? Compare two adjacent list elements and if they are out of order swap them. 
After a first pass the largest element will have bubbled to the end of the list. 
Each pass can look at one less element as the end of a list stays sorted.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000
#define MIN 0

#define RANGE 1000 // gap between Max and Min

#define random_num rand() % RANGE

typedef struct LIST
{
    int data;
    struct LIST *next;
} list;

list *create_list(int d)
{
    list *head = (list *)malloc(sizeof(list));
    head->data = d;
    head->next = NULL;
    return head;
}

void add_to_end(int d, list *h)
{
    list *ptr;
    list *temp = create_list(d);
    ptr = h;
    temp->data = d;
    temp->next = NULL;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

list *array_to_list(int d[], int size)
{
    list *head = create_list(d[0]);
    int i;
    for (i = 1; i < size; i++)
    {
        add_to_end(d[i], head);
    }
    return head;
}

void print_list(list *h, char *title)
{
    int count = 0;
    printf("%s\n", title);
    while (h != NULL)
    {
        printf("%d\t", h->data);
        h = h->next;
        if ((++count) % 10 == 0)
            printf("\n");
    }
}

void create_array(int len, int a[])
{
    int i;
    srand((unsigned)time(0));
    for (i = 0; i < len; i++)
    {
        a[i] = random_num;
    }
}

void print_array(int length, int width, int a[])
{
    int i;
    for (i = 0; i < length; i++)
    {
        printf("%d\t", a[i]);
        if ((i + 1) % 10 == 0)
            printf("\n");
    }
}

// void bubble(int data[], int how_many)
// {
//     int i,j;
//     int go_on;

//     for(i=0;i<how_many;i++)
//     {
//         print_array(how_many,data,"\ninside bubble\n");
//         printf("i=%d, input any int to continue:", i);
//         scanf("%d", &go_on);
//         for(j=how_many-1;i<j;j--)
//         if (data[j-1]>data[j])
//             swap(&data[j-1],&data[j]);
//     }
// }

void bubbleSort_list(list **h)
{
    list *prev = *h;
    list *behind;
    int temp;

    while (prev->next)
    {
        behind = prev->next;
        while (behind)
        {
            if (prev->data > behind->data)
            {
                temp = prev->data;
                prev->data = behind->data;
                behind->data = temp;
            }
            behind = behind->next;
        }
        prev = prev->next;
    }
}

void print_file(FILE * fptr)
{
    int c;
    rewind(fptr);
    while((c=getc(fptr))!=EOF)
    {
        putc(c, stdout);
    }
}

void double_space(FILE *ifp, FILE *ofp)
{
    int c;
    rewind(ifp);
    while((c=getc(ifp))!=EOF)
    {
        putc(c, ofp);
        // putchar(c);
        if (c=='\n')
            putc('\n', ofp);
    }

}

int main(int argc, char *argv[])
{
    int length = 100;
    int a[length];
    list *head = NULL;

    create_array(length, a);
    // print_array(length, 10, a);

    head = array_to_list(a, length);
    print_list(head, "data[100]made into a elements list");
    printf("\n++++++++++++++++++++\n");

    bubbleSort_list(&head);
    print_list(head, "bubble sorted list");
    printf("\n++++++++++++++++++++\n");
        printf("%%");

    return 0;

    // FILE *ifp, *ofp;

    // if(argc!=3)
    // {
    //     printf("Need excuteable inputfile outputfile\n");
    //     exit(1);
    // }

    // ifp = fopen(argv[1], "r+");
    // ofp = fopen(argv[2], "w+");
    // printf("my %s file as read is \n\n", argv[1]);
    // print_file(ifp);
    // printf("\n+++++++++++++++++++++\n");
    // double_space(ifp, ofp);
    // printf("my %s file double space is \n\n", argv[2]);
    // print_file(ofp);
    // printf("\n+++++++++++++++++++++\n");
    // fclose(ifp);
    // fclose(ofp);

    return 0;
}
