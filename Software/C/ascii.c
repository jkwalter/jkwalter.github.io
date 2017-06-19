/*
Compiling and Running in Linux:

 - Open a terminal
 - Navigate to the same directory as ascii.c
      cd ~/Programs/jkwalter.github.io/Software/C
 - Type the following to complie ascii.c
      gcc ascii.c
 - Type the following to run ascii.c
      ./a.out
*/

#include <stdio.h>

int main(void)
{
 int i;
 char c;

 for (i = 0; i < 128; i++)
  {
   c = i;
   printf("%3i: %c\n", i, c);
  }

 return 0;
}
