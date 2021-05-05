#include <stdio.h>

enum week{ Mon = 1, Tues, Wed, Thurs, Fri, Sat, Sun };

typedef enum choices
{
    left,
    left_center = 2,
    right_center,
    right = 5
} choices;

typedef enum week day;

void print_day(day d)
{
 switch(d){
        case Mon: puts("Monday"); break;
        case Tues: puts("Tuesday"); break;
        case Wed: puts("Wednesday"); break;
        case Thurs: puts("Thursday"); break;
        case Fri: puts("Friday"); break;
        case Sat: puts("Saturday"); break;
        case Sun: puts("Sunday"); break;
        default: puts("Error!");
    }
}

 day next_day( day d)
{
    return(d+1%7);
}

int main()
{   
    day d;
    scanf("%d", &d);
    print_day(d);
    print_day(next_day(d));
    // putc(choices.right_center);
    return 0;
}