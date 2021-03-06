/*
Compiling and Running in UNIX:

 - Open a terminal
 - Navigate to the same directory as digit.c
      cd ~/Documents/Programs/jkwalter.github.io/C
 - Type the following to compile digit.c
      gcc digit.c
 - Type the following to run digit.c
      ./a.out
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define DIGIT 7

int main(void)
{
 int i;
 int num;
 int tmp;
 int print;

 srand(time(NULL));

 for (i = 0; i < N; i++)
  {
   num = rand();
   tmp = num;
   print = 0;
   while (tmp != 0)
    {
     if (tmp % 10 == DIGIT && print == 0)
      {
       printf("%d\n", num);
       tmp = tmp / 10;
       print = 1;
      }
     else
      {
       tmp = tmp / 10;
      }
    }
  }

 return 0;
}
