#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main(void)
{
 int i;
 int j;
 int swap;
 int A[N] = {-1};

 srand(time(NULL));

 for (i = 0; i < N; i++)
  {
   A[i] = rand() % N;
   printf("%d ", A[i]);
  }
 printf("\n");

 for (i = 0; i < N; i++)
  {
   j = i;
   while (j > 0 && A[j] < A[j-1])
    {
     swap = A[j-1];
     A[j-1] = A[j];
     A[j] = swap;
     j--;
    }
  }

 for (i = 0; i < N; i++)
  {
   printf("%d ", A[i]);
  }
 printf("\n");

 return 0;
}
