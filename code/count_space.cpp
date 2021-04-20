/* 
count blanks, digits, and total __cpp_unicode_characters
demostrate loop with for statement
sjw.spirit@gmail.com 20.04.2021
 */

#include <stdio.h>

int count_char(int* C_blanks, int* C_digital, int* C_char, int* C_letters, int* C_others)
{
    // int blanks=0, digital = 0, totoal_chars =0, letters = 0, others =0;
    int c; // ust for int value of character
    for (; (c=getchar())!= EOF; *C_char++)
    {
        if (c == ' ')
        {
            // ++blanks;
            ++*C_blanks;
        }
        else if (c >= '0' && c <= '9')
        {
            // ++digital;
            ++*C_digital;
        }
        else if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'z')
        {
            // ++letters;
            ++*C_letters;
        }
        else 
        {
            // ++others;
            ++*C_others;
        }
    }
    return 0;
}

int main ()
{
    int blanks=0, digital = 0, totoal_chars =0, letters = 0, others =0;
    count_char(&blanks, &digital, &totoal_chars, &letters, &others);
    printf ("count chars= %d,\n \
            count blanks= %d,\n \
            count digital= %d,\n \
            count letters= %d,\n \
            count others= %d,\n", 
            totoal_chars, blanks, digital,letters, others);
}