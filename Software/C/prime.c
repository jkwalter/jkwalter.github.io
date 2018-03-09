/*
Compiling and Running in UNIX:

 - Open a terminal
 - Navigate to the same directory as prime.c
      cd ~/Documents/Programs/jkwalter.github.io/Software/C
 - Type the following to compile prime.c
      gcc prime.c
 - Type the following to run prime.c
      ./a.out

Compiling and Running in Microsoft Visual Studio:

 - Open Developer Command Prompt for Visual Studio
 - Navigate to the same directory as prime.c
      cd "C:\Users\Josh Walter\Documents\Programs\C"
 - Type the following to compile prime.c
      cl prime.c
 - Type the following to run prime.c
      prime
*/

#include <stdio.h>

#define N 500

int main(void)
{
 int i;
 int j;
 int print;

 printf("\n");
 printf("PRIME NUMBERS BETWEEN 2 and %d\n", N);
 printf("\n");

 for (i = 2; i <= N; i++)
  {
   print = 0;
   for (j = 2; j < i; j++)
    {
     if (i % j == 0)
      {
       print = 1;
      }
    }
   if (print == 0)
    {
     printf(" %3d\n", i);
    }
  }

 return 0;
}
