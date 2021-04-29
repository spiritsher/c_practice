#include <stdio.h>
#include <string.h>

typedef struct EMP
{
	char sex[8];
	char name[15];
	int age;
} emp; 

int main()
{
	emp p; 
	strcpy(p.sex, "male");
	strcpy(p.name, "zhangfei");
	p.age = 20;
	printf("sex is %s\n", p.sex);
	printf("name is %s\n", p.name);
	printf("Age is %d\n", p.age);
	return 0;
}
