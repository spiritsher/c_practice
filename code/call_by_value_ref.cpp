#include <stdio.h>

void foobar(int &n)
{
    n = n + 1;
    return;
}

int main()
{
    int k = 6;
    foobar(k);
    // printf("foobar(k) = %d, k = %d\n", foobar(k), k);
        printf("k = %d\n", k);

    return 0;
}
