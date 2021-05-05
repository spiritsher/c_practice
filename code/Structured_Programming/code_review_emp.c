/*
__________________________________________  OPTION 2  __________________________________________

Write a struct that has 
------------------------
a member that is the name of a business department: 
HR, Sales, Research, Software, and Executive (use enums for the 4 departments).  
------------------------
A second member that is an annual salary as an int. 
------------------------
A third member that is a social security number(unsigned).  
------------------------


Generate 10 employees with different social security numbers. 
Invent a salary generator for each department (use some base salary for the department 
and add in a randomly generated offset).  
Print out the 10 employees and their values to the screen-one line at a time.
*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MIN_SECUTIRY_NUM 100000
#define MAX_SECUTIRY_NUM 200000
#define BASE_ANNUAL_SALARY 50000

enum business_department {HR, Sales, Research, Software, Executive}; //Declare departaments

/*
Struct Employee with the features required
*/
typedef struct
{
    enum business_department dept;
    int anual_salary;
    unsigned int security_number;
} Employee;


/*
Function that generates an employee.
Choose their departament randomly,
based in the dep the salary is given,
social security number is generated randomly
*/
void employee_generator(Employee *ptr_emp)
{
    /*
    INPUT: pointer to the employee
    OUTPUT: no output, pass by reference 
    */
    int num_random_choose_BD = rand()%5;
    switch (num_random_choose_BD)
    {
    case 0:
        ptr_emp -> dept = HR;
        ptr_emp -> anual_salary = 1*BASE_ANNUAL_SALARY;
        break;
    case 1:
        ptr_emp -> dept = Sales;
        ptr_emp -> anual_salary = 1.5*BASE_ANNUAL_SALARY;
        break;
    case 2:
        ptr_emp -> dept = Research;
        ptr_emp -> anual_salary = 2*BASE_ANNUAL_SALARY;
        break;
    case 3:
        ptr_emp -> dept = Software;
        ptr_emp -> anual_salary = 2.5*BASE_ANNUAL_SALARY;
        break;
    case 4:
        ptr_emp -> dept = Executive;
        ptr_emp -> anual_salary = 3*BASE_ANNUAL_SALARY;
        break;
    }
    ptr_emp -> security_number = (MIN_SECUTIRY_NUM+rand()%(MAX_SECUTIRY_NUM-MIN_SECUTIRY_NUM));
}

/*
Function to print dept
*/
char* print_dep(enum business_department dept)
{
    /*
    INPUT: business_department dept
    OUTPUT: string of dept
    */
    switch (dept)
    {
    case HR:
        return "HR";
        break;
    case Sales:
        return "Sales";
        break;
    case Research:
        return "Research";
        break;
    case Software:
        return "Software";
        break;
    case Executive:
        return "Executive";
        break;
    }
}


int main(int argc, char const *argv[])
{
    srand(time(0));
    int i;
    Employee emp[10];
    for (i = 0; i < 10; i++){
        employee_generator(&emp[i]);
        printf("Employee %d \t Departament: %s,\t Annual salary: %d,\t Security number: %d \n",
                i, print_dep(emp[i].dept), emp[i].anual_salary, emp[i].security_number);
    }
    return 0;
}