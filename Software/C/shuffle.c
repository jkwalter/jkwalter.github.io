#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 15

struct list
{
 int original_order[N];
 int shuffle_order[N];
};

int main(void)
{
 int i;
 int j;
 int tmp_original;
 int tmp_shuffle;
 struct list order;
 int used[N] = {0};

 srand(time(NULL));

 for (i = 1; i < N; i++)
  {
   order.original_order[i] = i;
   do
    {
     order.shuffle_order[i] = rand() % (N - 1) + 1;
    } while (used[order.shuffle_order[i]] == 1);
   used[order.shuffle_order[i]] = 1;
   printf("Original: %2d -- Shuffle: %2d\n", order.original_order[i], order.shuffle_order[i]);
  }

 printf("\n");

 for (i = 1; i <= N - 1; i++)
  {
   for (j = 1; j <= N - i; j++)
    {
     if (order.shuffle_order[j] > order.shuffle_order[N-i])
      {
       tmp_original = order.original_order[N-i];
       tmp_shuffle = order.shuffle_order[N-i];
       order.original_order[N-i] = order.original_order[j];
       order.shuffle_order[N-i] = order.shuffle_order[j];
       order.original_order[j] = tmp_original;
       order.shuffle_order[j] = tmp_shuffle;
      }
    }
  } 

 for (i = 1; i < N; i++)
  {
   printf("Shuffle: %2d -- Original: %2d\n", order.shuffle_order[i], order.original_order[i]);
  }

 return 0;
}
