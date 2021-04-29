#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//不同的平台下引入不同的头文件
#if _WIN32 //识别windows平台
#include <windows.h>
#elif __linux__ //识别linux平台
#include <unistd.h>
#endif

#define MAX_SEAL_WT_M 8800
#define MIN_SEAL_WT_M 4400

// note female range is 880-2000 ls.

#define RANGE 4400
#define POPULATION 1000
#define WT_OVER rand() % RANGE
#define WT WT_OVER + MIN_SEAL_WT_M
#define FILL                         \
    for (i = 0; i < POPULATION; i++) \
    data[i] = WT

void print_data(int d[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d\t", d[i]);
        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }
    }
}

int main()
{
//不同的平台下调用不同的函数
#if _WIN32 //识别windows平台
    Sleep(5000);
#elif __linux__ //识别linux平台
    sleep(5);
#endif

    int i;
    int data[POPULATION];
    srand(time(0));
    FILL;
    print_data(data, POPULATION);
    printf("\n+++++++++++++++++++++\n");
    return 0;
}