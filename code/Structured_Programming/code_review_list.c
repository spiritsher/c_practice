#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>



/*defining the data type of list */

typedef struct list{ int data; struct list *next;} list;

int is_empty(const list *l) { return (l == NULL);}

list* create_list(int d)
{
    list* head = malloc(sizeof(list));
    head -> data = d;
    head -> next = NULL;
    return head;
}

list* add_to_front(int d, list* h)
{
    list* head = create_list(d);
    head -> next = h;
    return head;
}

list* array_to_list(int d[], int size)
{
    list* head =  create_list(d[0]);
    int i;
    for(i = 1; i < size; i++)
    {
        head = add_to_front(d[i], head);
    }
    return head;
}

void print_list(list *h, char *title)
{
    printf("%s\n", title);
    int c = 0;
    while (h != NULL){
        printf("%d, ", h -> data);
        c = c + 1;
        if (c%5==0) {printf("\n");}
        h = h -> next;
    }
}



/* writing the bubble sort function */

void sort(list *h)
{
    h -> data = h -> data + h -> next -> data;
    h -> next -> data = h -> data - h -> next -> data;
    h -> data = h -> data - h -> next -> data;
}

list* bubble_sort(list *h)
{
    int t = 0;
    for (t = 0; t < 99; t++) {
        list *p = h;
        int i = 0;
        for (i = 0; i<99-t; i++) {
            if (p -> data > p -> next -> data) {sort(p);}
            p = p -> next;
        }
    }
    return h;
}



/* 	the main function
         (generating a list of 100 random integers, printing the list,
         sorting the list, and printing the sorted list)
*/

int main()
{
    list list_of_int;
    list* head = NULL;
    int my_array[100];
    int i = 0;
    for (i = 0; i < 100; i++) {
        my_array[i] = rand();
    }
    head = array_to_list(my_array, 100);
    printf("\n\n");
    print_list(head, "100 random number list");
    printf("\n\n");
    print_list(bubble_sort(head), "sorted 100 random number list");
    printf("\n\n");
}