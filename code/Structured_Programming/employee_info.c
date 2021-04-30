/* Employee_info_list

REQ: 
1.  Write a struct that has a member that is the name of a business department: 
    HR, Sales, Research, Software, and Executive (use enums for the 4 departments).  
2.  A second member that is an annual salary as an int. 
3.  A third member that is a social security number(unsigned).  
4.  Generate 10 employees with different social security numbers. 
5.  Invent a salary generator for each department (use some base salary for the department and add in a randomly generated offset).  
6.  Print out the 10 employees and their values to the screen-one line at a time.

RoadMap:
input elements for stack;
    auto generate id string DE+random"FFFFFFFF";
    struct also included an union datatype;
push struct into stack one by one;
after achieve 10 elements, pop element one by one.

Note:
input seq: name(%s), dept(%u) <HR,Sales,RD,SW,Exec>, contract_type(%c), Level(%s) or Period(%d)    
name    dept    contract_type   LevelorPeriod
AA 1 T 1
BB 2 T 2
CC 3 T 3
DD 4 T 4
EE 5 T 5
FF 1 P SL1
GG 2 P SL2
HH 3 P SL3
II 4 P SL4
JJ 5 P SL5

Result:
Index           Name            Dept            social_id               Salary          contract_type           period or Level
9               JJ              Exec            DE41A6A219              7387            P               SL5
8               II              SW              DE1B9486FD              5842            P               SL4
7               HH              RD              DE4834EB38              4867            P               SL3
6               GG              Sales           DE34C7F61A              4364            P               SL2
5               FF              HR              DE3CB45EF0              5252            P               SL1
4               EE              Exec            DE4D3133C1              5505            T               5
3               DD              SW              DE15956A6D              8059            T               4
2               CC              RD              DE1ECEACD5              6819            T               3
1               BB              Sales           DE55277FEF              4318            T               2
0               AA              HR              DE4B5380E0              8737            T               1

Question:
1. how to free ID_string=malloc(xxx), when it is a return?
2. is it necessary for release stack?


sjw.spirit@gmail.com
28.04.2021 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SAL 9000 //max salary
#define MIN_SAL 4000 //min salary

#define RANGE 5000 //salary gap between Max and Min

#define TOTAL 10 //total employee
#define SA_OVER rand() % RANGE
#define SA SA_OVER + MIN_SAL
// #define FILL                    \
//     for (i = 0; i < TOTAL; i++) \
//     data[i] = SA

#define EMPTY -1
#define FULL (TOTAL - 1)

typedef enum SECTION{HR = 1,Sales,RD,SW,Exec}Section;

// typedef enum Section dept;

// char *GEN_ID(int len); //generate ID_String=states_code+random("FF...FFF") maximual 6byte, eg: FFFF FFFF FFFF
char *GEN_ID(void);
char *StringDirectionT(Section *sec);

typedef struct EMPLY_INFO
{
    int index;
    char name[20];
    Section dept;
    int salary;
    char *social_id;
    char contract_type; //p = Permanent, T =template;
    union
    {
        int period;     //T: contract avaiable year.
        char Level[20]; // P: level.
    } ct;
} emply_info;

typedef struct stack
{
    emply_info s[TOTAL];
    int top;
} stack;

void reset(stack *stk)
{
    stk->top = EMPTY;
}

void push(emply_info c, stack *stk)
{
    stk->top++;
    stk->s[stk->top] = c;
}

emply_info pop(stack *stk)
{
    return (stk->s[stk->top--]);
}

emply_info top(const stack *stk)
{
    return (stk->s[stk->top]);
}

int is_empty(const stack *stk)
{
    return (stk->top == EMPTY);
}

int is_full(const stack *stk)
{
    return (stk->top == FULL);
}

int main()
{
    emply_info employee;
    stack stack_of_em_info;
    reset(&stack_of_em_info);

    int i=0;

    // emply_info* employee = new emply_info;
    printf("Input info: \nname\tdept\tcontract_type\tLevelorPeriod\n");
    while (!is_full(&stack_of_em_info))
    //   while (i < TOTAL)
  
    {
        employee.index = i++;
        scanf("%s %u %c", employee.name, &(employee.dept), &(employee.contract_type));

        if (employee.contract_type == 'P')
        {
            scanf("%s", employee.ct.Level); //Permanent contract
        }
        else //Temporary contract
        {
            scanf("%d", &employee.ct.period);
        }
        employee.social_id = GEN_ID();
        employee.salary = SA;
        push(employee, &stack_of_em_info);
    }

    printf("\nIndex\t\tName\t\tDept\t\tsocial_id\t\tSalary\t\tcontract_type\t\tperiod or Level\n");
    // i = 0;
    while (!is_empty(&stack_of_em_info))
    {
        employee = pop(&stack_of_em_info);

        if (employee.contract_type == 'P')       //Permanent contract
        { 
            printf("%d\t\t%s\t\t%s\t\t%s\t\t%d\t\t%c\t\t%s\n", employee.index, employee.name, StringDirectionT(&(employee.dept)), employee.social_id, \
            employee.salary,employee.contract_type,employee.ct.Level);
        }
        else                                        //Temporary contract
        { 
             printf("%d\t\t%s\t\t%s\t\t%s\t\t%d\t\t%c\t\t%d\n", employee.index, employee.name, StringDirectionT(&(employee.dept)), employee.social_id,employee.salary,employee.contract_type,employee.ct.period);
        }
    
    }

    return 0;
}

char *GEN_ID(void)
{
    int i;
    unsigned ID;
    // char *empy_id;
    unsigned max_Hex = 0xFFFFFFFF;

    srand((unsigned)time(0));

    ID = rand() % max_Hex;

    // unsigned a;
    // char *s;

    // for (i = 0; i < len; i++)
    // {
    //     strcat(s, "F");
    // }
    // puts(s);

    // a = strtoul(s, &s, 16);

    // char *string = malloc(strlen(s) + 1);
    char *string = malloc(9);
    char *state = "DE";
    char *ID_string = malloc(strlen(state) + strlen(string));

    sprintf(string, "%08X", ID);
    strcpy(ID_string, state);
    strcat(ID_string, string);
    puts(ID_string);

    // empy_id = ID_string;
    // printf("integer = %d string = %s\n", ID, string);
    // printf("ID_string = %s\n", ID_string);

    // printf("The string 'str' is %s and the number 'num' is %X. \n",s, a);
    // free(s);
    // s = NULL;

    free(string);
    string = NULL;

    // free(ID_string);
    // ID_string = NULL;

    return ID_string;
}

char * StringDirectionT(Section *sec)
{
    switch(*sec)
    {
        case HR: return "HR";
        case Sales: return "Sales";
        case RD: return "RD";       
        case SW: return "SW";
        case Exec: return "Exec";
        default: printf("Illegal value!\n");
    }
}
