/*
Compiling and Running in Linux:

 - Open a terminal
 - Navigate to the same directory as fibonacci.c
 - Type the following to complie fibonacci.c
      gcc fibonacci.c
 - Type the following to run fibonacci.c
      ./a.out
*/

#include <stdio.h>

int main(void)
{
 int i;
 int num;
 long x;
 long y;

 x = 0;
 y = 1;

 printf("===================\n");
 printf(" FIBONACCI NUMBERS \n");
 printf("===================\n");
 do
  {
   printf("Enter a number greater than 1 and less than 92: ");
   scanf("%d", &num);
  } while (num <= 1 && num > 92);

 printf("\n");

 printf(" 0: %ld\n", x);
 printf(" 1: %ld\n", y);

 for (i = 2; i <= num; i++)
  {
   y = x + y;
   x = y - x;
   printf("%2d: %ld\n", i, y);
  }

 return 0;
}
