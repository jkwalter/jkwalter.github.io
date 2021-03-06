/*
Compiling and Running in UNIX:

 - Open a terminal
 - Navigate to the same directory as password.c
      cd ~/Documents/Programs/jkwalter.github.io/C
 - Type the following to compile password.c
      gcc password.c
 - Type the following to run password.c
      ./a.out
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 8

int main(void)
{
 int i;
 int x;
 char c;

 srand(time(NULL));

 for (i = 0; i < N; i++)
  {
   x = rand() % 3;
   if (x == 0)
    {
     c = rand() % 10 + '0';
    }
   else if (x == 1)
    {
     c = rand() % 26 + 'a';
    }
   else
    {
     c = rand() % 26 + 'A';
    }
   printf("%c", c);
  }

 printf("\n");

 return 0;
}
