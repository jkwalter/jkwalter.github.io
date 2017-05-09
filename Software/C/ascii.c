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
