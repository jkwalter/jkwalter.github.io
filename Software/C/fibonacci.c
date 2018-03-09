/*
Compiling and Running in UNIX:

 - Open a terminal
 - Navigate to the same directory as fibonacci.c
      cd ~/Documents/Programs/jkwalter.github.io/Software/C
 - Type the following to compile fibonacci.c
      gcc fibonacci.c
 - Type the following to run fibonacci.c
      ./a.out

Compiling and Running in Microsoft Visual Studio:

 - Open Developer Command Prompt for Visual Studio
 - Navigate to the same directory as fibonacci.c
      cd "C:\Users\Josh Walter\Documents\Programs\C"
 - Type the following to compile fibonacci.c
      cl fibonacci.c
 - Type the following to run fibonacci.c
      fibonacci
*/

#include <stdio.h>

void fibonacci(long x, long y, int i, int n)
{
 printf(" %2d: %ld\n", i, x + y);

 if (i < n)
  {
   fibonacci(y, x + y, i + 1, n);
  }
}

int main(void)
{
 long x = 0;
 long y = 1;
 int i = 0;

 printf("===========================\n");
 printf(" FIBONACCI NUMBERS: 0 - 50 \n");
 printf("===========================\n");
 printf("\n");

 printf(" %2d: %ld\n", i, x);
 i++;
 printf(" %2d: %ld\n", i, y);

 fibonacci(x, y, i + 1, 50);

 return 0;
}
