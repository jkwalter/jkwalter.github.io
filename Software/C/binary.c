#include <stdio.h>
#include <stdlib.h>

typedef struct linklist *node;

struct linklist
{
 int digit;
 node next;
};

node createNode(int value)
{
 node tmp;

 tmp = malloc(sizeof(node));
 tmp->digit = value;
 tmp->next = NULL;

 return tmp;
}

node push(node list, int value)
{
 node tmp;

 tmp = createNode(value);
 tmp->next = list;

 return tmp;
}

void pop(node list)
{
 node tmp;

 tmp = list;

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
   printf("Enter any number greater than 1: ");
   scanf("%d", &num);
  } while (num < 2);

 printf("\n");
 printf("Decimal number: %d\n", num);
 printf("Binary conversion: ");

 while (num != 0)
  {
   if (num % 2 == 1)
    {
     list = push(list, 1);
    }
   else
    {
     list = push(list, 0);
    }
   num = num / 2;
  }

 pop(list);

 printf("\n");

 return 0;
}
