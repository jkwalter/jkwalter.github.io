/*
Compiling and Running in UNIX:

 - Open a terminal
 - Navigate to the same directory as leapyear.c
      cd ~/Documents/Programs/jkwalter.github.io/Software/C
 - Type the following to compile leapyear.c
      gcc leapyear.c
 - Type the following to run leapyear.c
      ./a.out

Compiling and Running in Microsoft Visual Studio:

 - Open Developer Command Prompt for Visual Studio
 - Navigate to the same directory as leapyear.c
      cd "C:\Users\Josh Walter\Documents\Programs\C"
 - Type the following to compile leapyear.c
      cl leapyear.c
 - Type the following to run leapyear.c
      leapyear
*/

#include <stdio.h>

int main(void)
{
 int year;

 do
  {
   printf("Enter a year (0-9999): ");
   scanf("%d", &year);
  } while (year < 0 && year > 9999);

 if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
  {
   printf("%d is a leap year.\n", year);
  }
 else
  {
   printf("%d is not a leap year.\n", year);
  }

 return 0;
}
