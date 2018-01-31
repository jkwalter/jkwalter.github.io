#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

typedef struct linklist *node;

struct linklist
{
 int number;
 node next;
 node previous;
};

node append_list(int value, node list)
{
 node temporary;
 node create;

 if (list == NULL)
  {
   create = malloc(sizeof(node));
   create->number = value;
   create->next = list;
   create->previous = list;

   return create;
  }
 else
  {
   temporary = list;
   while (temporary->next != NULL)
    {
     temporary = temporary->next;
    }
   create = malloc(sizeof(node));
   create->number = value;
   create->next = temporary->next;
   temporary->next = create;
   create->previous = temporary;

   return list;
  }
}

void print_list(node list)
{
 node temporary;

 if (list != NULL)
  {
   temporary = list;
   while (temporary != NULL)
    {
     printf(" %d", temporary->number);
     temporary = temporary->next;
    }
   printf("\n");
  }
}

void print_list_backwards(node list)
{
 node temporary;

 if (list != NULL)
  {
   temporary = list;
   while (temporary->next != NULL)
    {
     temporary = temporary->next;
    }
   while (temporary != NULL)
    {
     printf(" %d", temporary->number);
     temporary = temporary->previous;
    }
   printf("\n");
  }
}

node remove_pick(node list, int pick)
{
 node temporary;
 node remove;

 if (list != NULL)
  {
   temporary = list;
   if (temporary->number == pick)
    {
     remove = temporary;
     temporary = remove->next;
     temporary->previous = remove->previous;
     free(remove);
     return temporary;
    }
   else
    {
     while (temporary->number != pick)
      {
       temporary = temporary->next;
      }
     remove = temporary;
     temporary = remove->previous;
     temporary->next = remove->next;
     if (temporary->next != NULL)
      {
       temporary = temporary->next;
       temporary->previous = remove->previous;
      }
     free(remove);
     return list;
    }
  }
}

void delete_list(node list)
{
 node temporary;

 if (list != NULL)
  {
   while (list != NULL)
    {
     temporary = list;
     list = list->next;
     free(temporary);
    }
  } 
}

int main(void)
{
 int i;
 int value;
 int pick;
 int used[N] = {0};
 node list;

 srand(time(NULL));

 list = NULL;

 for (i = 0; i < N; i++)
  {
   do
    {
     value = rand() % N;
    } while (used[value] == 1);
   used[value] = 1;
   list = append_list(value, list);
  }

 print_list(list);
 print_list_backwards(list);
 pick = rand() % N;
 list = remove_pick(list, pick);
 print_list(list);
 print_list_backwards(list);
 delete_list(list);

 return 0;
}
