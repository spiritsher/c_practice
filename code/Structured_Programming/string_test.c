
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // char *firstName = "Theo";
    // char *lastName = "Tsao";
    // char *name = (char *) malloc(strlen(firstName) + strlen(lastName)+1);
    // strcpy(name, firstName);
    // strcat(name, lastName);
    // printf("%s\n", name);

    char* name=malloc(20);
    scanf("%s", name);
    puts(name);
    return 0;
}