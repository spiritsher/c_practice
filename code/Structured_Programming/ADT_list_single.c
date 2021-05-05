#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct LIST
{
    int data;
    struct LIST *next;
} list;

int is_empty(const list *l) { return (l == NULL); };

list *create_list(int d)
{
    list *head = (list *)malloc(sizeof(list));
    head->data = d;
    head->next = NULL;
    return head;
}

list *add_to_front(int d, list *h)
{
    list *head = create_list(d);
    head->next = h;
    return head;
}

void add_to_front2(int d, list **h)
{
    list *ptr = create_list(d);

    ptr->next = *h;
    *h = ptr;
}

list *del_at_front(list *h)
{
    if (h == NULL)
    {
        printf("list is already empty!\n");
    }
    else
    {
        list *temp = h;
        h = h->next;
        free(temp);
        temp = NULL;
    }
    return h;
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

void del_at_end(list *h)
{

    if (h == NULL)
    {
        printf("list is already empty!\n");
    }
    else if (h->next == NULL)
    {
        free(h);
        h = NULL;
    }
    else
    {
        list *temp = h;
        list *temp2 = h;
        while (temp->next != NULL)
        {
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = NULL;
        free(temp);
        temp = NULL;
    }
}

void add_at_pos(int d, int pos, list *h)
{
    list *ptr = h;
    list *ptr2 = create_list(d);

    pos--;
    while (pos != 1)
    {
        ptr = ptr->next;
        pos--;
    }
    ptr2->next = ptr->next;
    ptr->next = ptr2;
}

void del_pos(int pos, list **h)
{
    list *current = *h;
    list *previous = *h;
    if (*h == NULL)
        printf("list is already empty!");
    else if (pos == 1)
    {
        *h = current->next;
        free(current);
        current = NULL;
    }
    else
    {
        while (pos != 1)
        {
            previous = current;
            current = current->next;
            pos--;
        }
        previous->next = current->next;
        free(current);
        current = NULL;
    }
}

list *del_entire(list *h)
{
    if (h == NULL)
        printf("list is already empty!");
    else
    {
        list *temp = h;
        while (temp != NULL)
        {
            temp = temp->next;
            free(h);
            h = temp;
        }
        return h;
    }
}

list *reverse_list(list *h)
{
    list *prev = NULL;
    list *next = NULL;
    while(h!=NULL)
    {
        next = h->next;
        h->next = prev;
        prev = h;
        h = next;
    }
    h = prev;
    return h;
}

list *array_to_list(int d[], int size)
{
    list *head = create_list(d[0]);
    int i;
    for (i = 1; i < size; i++)
    {
        head = add_to_front(d[i], head);
    }
    return head;
}

void print_list(list *h, char *title)
{
    printf("%s\n", title);
    while (h != NULL)
    {
        printf("%d:", h->data);
        h = h->next;
    }
}

int main()
{
    list list_of_int;
    list *head = NULL;
    int data[6] = {2, 3, 5, 7, 8, 9};
    head = array_to_list(data, 6);
    // printf("sizeof(list)=%lu\n", sizeof(list));
    // head->data = 5;
    // head->next = NULL;
    print_list(head, "data[6]made into a elements list");
    printf("\n++++++++++++++++++++\n");
    add_to_end(5, head);
    print_list(head, "new list added at end");
    printf("\n++++++++++++++++++++\n");
    head = del_at_front(head);
    print_list(head, "deleted head list");
    printf("\n++++++++++++++++++++\n");
    del_at_end(head);
    print_list(head, "deleted end list");
    printf("\n++++++++++++++++++++\n");
    del_pos(3, &head);
    print_list(head, "deleted pos list");
    printf("\n++++++++++++++++++++\n");
    add_at_pos(15, 4, head);
    print_list(head, "deleted pos list");
    printf("\n++++++++++++++++++++\n");
    add_to_front2(11, &head);
    print_list(head, "another method add head");
    printf("\n++++++++++++++++++++\n");
    // head = del_entire(head);
    // if (head == NULL)
    //     printf("Entire array deleted successfully!\n");
    head = reverse_list(head);
    print_list(head, "reversed list");
    printf("\n++++++++++++++++++++\n");
    return 0;
}