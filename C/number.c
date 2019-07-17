/*
Compiling and Running in UNIX:

 - Open a terminal
 - Navigate to the same directory as number.c
      cd ~/Documents/Programs/jkwalter.github.io/C
 - Type the following to compile number.c
      gcc number.c
 - Type the following to run number.c
      ./a.out
*/

#include <stdio.h>

int main(void)
{
 int number;

 printf("Enter a number: ");
 scanf("%d", &number);

 if (number > 0)
  {
   printf("%d is positive.\n", number);
  }
 else if (number < 0)
  {
   printf("%d is negative.\n", number);
  }
 else
  {
   printf("%d is zero.\n", number);
  }

 return 0;
}
