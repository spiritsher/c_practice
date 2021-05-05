#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, const char *argv[]) {
    char *c_str = NULL;
    size_t len;

    if (argc != 2) {
        printf("Usage: ./program string\n");
        exit(EXIT_FAILURE);
    }

    if ((len = strlen(argv[1])) >= 4) {
        c_str = (char *)malloc(len);

        if (!c_str) {
            perror("malloc");
        }

        strcpy(c_str, argv[1]);
        printf("%s\n", c_str);
    } else {
        c_str = "Some Literal String";
        printf("%s\n", c_str);
    }
    free(c_str);

    exit(EXIT_SUCCESS);
}