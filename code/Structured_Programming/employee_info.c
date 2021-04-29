/* Employee_info_list

REQ: 
1.  Write a struct that has a member that is the name of a business department: 
    HR, Sales, Research, Software, and Executive (use enums for the 4 departments).  
2.  A second member that is an annual salary as an int. 
3.  A third member that is a social security number(unsigned).  
4.  Generate 10 employees with different social security numbers. 
5.  Invent a salary generator for each department (use some base salary for the department and add in a randomly generated offset).  
6.  Print out the 10 employees and their values to the screen-one line at a time.

Note:
input seq: name(%s), dept(%s) <HR,Sales,RD,SW,Exec>, contract_type(%c), Level(%s) or Period(%d)    


result:


sjw.spirit@gmail.com
28.04.2021 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SAL 9000 //max salary
#define MIN_SAL 4000 //min salary

#define RANGE 5000 //salary gap between Max and Min

#define TOTAL 10 //total employee
#define SA_OVER rand() % RANGE
#define SA SA_OVER + MIN_SAL
// #define FILL                    \
//     for (i = 0; i < TOTAL; i++) \
//     data[i] = SA

enum Section{HR = 1,Sales,RD,SW,Exec};

// typedef enum Section dept;

char *GEN_ID(int len); //generate ID_String=states_code+random("FF...FFF") maximual 6byte, eg: FFFF FFFF FFFF

struct emply_info
{
    int index;
    char *name;
    enum Section dept;
    int salary;
    char* social_id;
    char contract_type; //p = Permanent, T =template;
    union
    {
        int period;     //T: contract avaiable year.
        char Level[20]; // P: level.
    } ct;
} employee[TOTAL];

int main()
{
    int i;
    for (i = 0; i < TOTAL; i++)
    {
        printf("Input info: name\tdept\tcontract_type\tLevelorPeriod\n");
        employee[i].index = i;
        scanf("%s %d %c", employee[i].name, &(employee[i].dept), &(employee[i].contract_type));
        
        if (employee[i].contract_type == 'P')
        { 
            scanf("%s", &employee[i].ct.Level); //Permanent contract
        }
        else
        { if (employee[i].contract_type == 'T')  //Temporary contract
            scanf("%d", &employee[i].ct.period);
        }
        employee[i].social_id = GEN_ID(8);
        employee[i].salary = SA;
        fflush(stdin);
    }
    //输出人员信息
    printf("\n\t\tIndex\tName\tDept\tsocial_id\tSalary\tcontract_type\tperiod or Level\n");
    for (i = 0; i < TOTAL; i++)
    {
        if (employee[i].contract_type == 'P')       //Permanent contract
        { 
            printf("%d\t%s\t%s\t%s\t%d\t\t%c\t%s\n", employee[i].index, employee[i].name, employee[i].dept, employee[i].social_id, \
            employee[i].salary,employee[i].contract_type,employee[i].ct.Level);
        }
        else                                        //Temporary contract
        { 
             printf("%d\t%s\t%s\t%s\t%d\t\t%c\t%d\n", employee[i].index, employee[i].name, employee[i].dept, employee[i].social_id, \
            employee[i].salary,employee[i].contract_type,employee[i].ct.period);
        }
    }
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
    // puts(s);

    a = strtoul(s, &s, 16);

    char* string = malloc(strlen(s) + 1);
    char* state = "DE";
    char* ID_string = malloc(strlen(state)+strlen(string));

    sprintf(string, "%08X", ID);
    strcpy(ID_string, state);
    strcat(ID_string, string);
    puts(ID_string);
    // printf("integer = %d string = %s\n", ID, string);
    // printf("ID_string = %s\n", ID_string);

    // printf("The string 'str' is %s and the number 'num' is %X. \n",s, a);

    return ID_string;
}