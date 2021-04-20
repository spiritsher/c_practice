/* 
count blanks, digits, and total __cpp_unicode_characters
demostrate loop with for statement
sjw.spirit@gmail.com 20.04.2021
 */

#include <stdio.h>

int count_char()
{
    int blanks=0, digital = 0, totoal_chars =0, letters = 0, others =0;
    int c; // ust for int value of character
    for (; (c=getchar())!= EOF; totoal_chars++)
    {
/*         switch (c)
            {
                case (c == ' '):
                    ++blanks;
                    break;
    
                case (c >= '0' && c <= '9'):
                    ++digital;
                    break;

                case (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'z'):
                    ++letters;
                    break;

                default:
                    ++others;
                    break;
            } */

        // wrong, swith case only fit for constant expression. 

        if (c == ' ')
        {
            ++blanks;
        }
        else if (c >= '0' && c <= '9')
        {
            ++digital;
        }
        else if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'z')
        {
            ++letters;
        }
        else 
        {
            ++others;
        }

    }
    
    printf ("count chars= %d,\n \
            count blanks= %d,\n \
            count digital= %d,\n \
            count letters= %d,\n \
            count others= %d,\n", 
            totoal_chars,blanks, digital,letters, others);

    return 0;

}

int main ()
{
    count_char();
}