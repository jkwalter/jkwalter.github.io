/*
Compiling and Running in Linux:

 - Open a terminal
 - Navigate to the same directory as binary.c
      cd ~/Programs/jkwalter.github.io/Software/C
 - Type the following to complie binary.c
      gcc binary.c
 - Type the following to run binary.c
      ./a.out
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct linklist *node;

struct linklist
{
 int digit;
 node next;
};

node push(node list, int value)
{
 node tmp;

 tmp = malloc(sizeof(node));
 tmp->digit = value;
 tmp->next = list;

 return tmp;
}

void pop(node list)
{
 node tmp;

 while (list != NULL)
  {
   printf("%d", list->digit);
   tmp = list;
   list = list->next;
   free(tmp);
  }
}

int main(void)
{
 int num;
 node list;

 list = NULL;

 do
  {
   printf("Enter any positive number: ");
   scanf("%d", &num);
  } while (num < 1);

 printf("\n");
 printf("Decimal number: %d\n", num);
 printf("Binary conversion: ");

 while (num != 0)
  {
   list = push(list, num % 2);
   num = num / 2;
  }

 pop(list);

 printf("\n");

 return 0;
}
