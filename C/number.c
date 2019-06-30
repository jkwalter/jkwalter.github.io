/*
Compiling and Running in UNIX:

 - Open a terminal
 - Navigate to the same directory as number.c
      cd ~/Documents/Programs/jkwalter.github.io/Software/C
 - Type the following to compile number.c
      gcc number.c
 - Type the following to run number.c
      ./a.out

Compiling and Running in Microsoft Visual Studio:

 - Open Developer Command Prompt for Visual Studio
 - Navigate to the same directory as number.c
      cd "C:\Users\Josh Walter\Documents\Programs\C"
 - Type the following to compile number.c
      cl number.c
 - Type the following to run number.c
      number
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
