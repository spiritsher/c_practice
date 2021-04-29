#define _OPEN_SYS_ITOA_EXT

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

 char* GEN_ID(int bits);
// int arrayToStr(unsigned char *buf, unsigned int buflen, char *out);

// char * utoa(unsigned int n, char * buffer, int radix);

int main()
{
    char *ff;
    ff= GEN_ID(8);
    puts(ff);
    return 0;
}

 char* GEN_ID( int len)
{
    int i;
    unsigned ID;


    unsigned max_Hex = 0xFFFFFFFF;

    srand((unsigned)time(0));

    ID = rand() % max_Hex;

    unsigned a;
    char* s;

    for (i = 0; i < len;i++)
    {
        strcat(s, "F");
    }
    puts(s);

    a = strtoul(s, &s, 16);

    char* string = malloc(strlen(s) + 1);
    char* state = "DE";
    char* ID_string = malloc(strlen(state)+strlen(string));

    sprintf(string, "%08X", ID);
    strcpy(ID_string, state);
    strcat(ID_string, string);
    puts(ID_string);
    printf("integer = %d string = %s\n", ID, string);
    // printf("ID_string = %s\n", ID_string);

    printf("The string 'str' is %s and the number 'num' is %X. \n",s, a);

    return ID_string;
}
