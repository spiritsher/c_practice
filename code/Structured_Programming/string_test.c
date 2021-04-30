
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fun(const char **s, int lengh);
char *fun1(int lengh);


int main() {
    // char *firstName = "Theo";
    // char *lastName = "Tsao";
    // char *name = (char *) malloc(strlen(firstName) + strlen(lastName)+1);
    // strcpy(name, firstName);
    // strcat(name, lastName);
    // printf("%s\n", name);

    // // char* name=malloc(20);
    // // scanf("%s", name);
    // puts(name);
    // free(name);
    // return 0;
    // char* s;
    // int i;
    // for (i = 0; i < 8; i++)
    // {
    //     strcat(s, "F");
    // }
    //     puts(s);
    //     return 0;
    char *p, *p1;
    int length = 8;
    fun(&p, length);
    puts(p);
    p1 = fun1(length);
    puts(p1);
    return 0;
}

void fun(const char** s, int lengh)
{
    int i;
    // char *s1;
    char *s2= (char *)malloc(lengh+1);
    // s2 = s3;
    for (i = 0; i < lengh; i++)
    {
        s2[i] = 'F';
    }
        // *s1 = *s2;
        strcpy(*s, s2);
    // *s = s2;
    puts(*s);
    free(s2);
    // return s1;
}

char* fun1(int lengh)
{
    int i;
    char *s1="aaaaaaaa";
    char *s3= (char *)malloc(lengh+1);
    // s2 = s3;
    for (i = 0; i < lengh; i++)
    {
        s3[i] = 'F';
    }
        // *s1 = *s2;
        strcpy(s1, s3);
    puts(s1);
    return s1;
    // free(s2);
    return s1;
}