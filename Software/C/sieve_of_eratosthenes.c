#include <stdio.h>
#include <math.h>

#define N 24

int main(void)
{
 int i;
 int j;
 int range;
 int A[N+1] = {0};

 range = sqrt(N);

 for (i = 2; i < range; i++)
  {
   for (j = 2; j < N; j++)
    {
     if (j * i < N + 1)
      {
       A[j * i] = 1;
      }
    }
  }

 for (i = 2; i < N + 1; i++)
  {
   if (A[i] == 0)
    {
     printf(" %3d\n", i);
    }
  }

 return 0;
}
