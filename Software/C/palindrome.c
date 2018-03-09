/*
Compiling and Running in UNIX:

 - Open a terminal
 - Navigate to the same directory as palindrome.c
      cd ~/Documents/Programs/jkwalter.github.io/Software/C
 - Type the following to compile palindrome.c
      gcc palindrome.c
 - Type the following to run palindrome.c
      ./a.out

Compiling and Running in Microsoft Visual Studio:

 - Open Developer Command Prompt for Visual Studio
 - Navigate to the same directory as palindrome.c
      cd "C:\Users\Josh Walter\Documents\Programs\C"
 - Type the following to compile palindrome.c
      cl palindrome.c
 - Type the following to run palindrome.c
      palindrome
*/

#include <stdio.h>

int main(void)
{
 int i;
 int count = 1;

 for (i = 0; i < 2000; i++)
  {
   if (i < 10)
    {
     printf("%2d: %d\n", count, i);
     count++;
    }
   else if (i < 100)
    {
     if (i % 11 == 0)
      {
       printf("%2d: %d\n", count, i);
       count++;
      }
    }
   else if (i < 1000)
    {
     if (i / 100 == i % 10)
      {
       printf("%2d: %d\n", count, i);
       count++;
      }
    }
   else
    {
     if (i % 10 == i / 1000 && i / 10 % 10 == i / 100 % 10)
      {
       printf("%2d: %d\n", count, i);
       count++;
      }
    }
  }

 return 0;
}
