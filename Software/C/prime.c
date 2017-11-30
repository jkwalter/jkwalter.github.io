#include <stdio.h>

int main(void)
{
 int i;
 int j;
 int N;
 int print;

 do
  {
   printf("Enter a number greater than 2 and less than 500: ");
   scanf("%d", &N);
  } while (N < 3 && N > 501);

 printf("\n");
 printf("PRIME NUMBERS BETWEEN 2 and %d\n", N);
 printf("\n");

 for (i = 2; i < N; i++)
  {
   print = 0;
   for (j = 2; j < i; j++)
    {
     if (i % j == 0)
      {
       print = 1;
      }
    }
   if (print == 0)
    {
     printf(" %3d\n", i);
    }
  }

 return 0;
}
