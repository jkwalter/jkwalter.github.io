/*
Compiling and Running in Linux:

 - Open a terminal
 - Navigate to the same directory as stars.c
      cd ~/Programs/jkwalter.github.io/Software/C
 - Type the following to complie stars.c
      gcc stars.c
 - Type the following to run stars.c
      ./a.out
*/

#include <stdio.h>

int main(void)
{
 int i;
 int j;
 int num;

 do
  {
   printf("Enter a positive number less than or equal to 20: ");
   scanf("%d", &num);
  } while (num < 1 || num > 20);

 printf("\n");

 for (i = 0; i < num; i++)
  {
   for (j = num; j > i; j--)
    {
     printf("*");
    }
   printf("\n");
  }

 return 0;
}
