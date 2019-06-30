#include <stdio.h>

int main(void)
{
 int i;
 int multiplier = 0;
 int product = 0;
 int sum = 0;
 float average;

 printf("Enter a number: ");
 scanf("%d", &multiplier);

 for (i = 0; i < 10; i++)
  {
   product = (i + 1) * multiplier;
   printf("%d x %d = %d\n", i + 1, multiplier, product);
   sum = sum + product;
  } 

 printf("Sum of Products: %d\n", sum);
 printf("Count of Products: %d\n", i);

 average = sum / (i * 1.0);
 printf("Average of Products: %f\n", average);

 return 0;
}
