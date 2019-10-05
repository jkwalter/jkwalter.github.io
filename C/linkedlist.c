/*
Compiling and Running in UNIX:

 - Open a terminal
 - Navigate to the same directory as linklist.c
      cd ~/Documents/Programs/jkwalter.github.io/C
 - Type the following to compile linklist.c
      gcc linklist.c
 - Type the following to run linklist.c
      ./a.out
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

typedef struct linklist *node;

struct linklist
{
 int value;
 node next;
};

node append_list(node list, int number)
{
 node temporary;
 node create;

 temporary = list;

 if (temporary == NULL)
  {
   create = malloc(sizeof(node));
   create->value = number;
   create->next = NULL;

   return create;
  }
 else
  {
   while (temporary->next != NULL)
    {
     temporary = temporary->next;
    }
   create = malloc(sizeof(node));
   create->value = number;
   create->next = temporary->next;
   temporary->next = create;

   return list;
  }
}

void print_list(node list)
{
 node temporary;

 temporary = list;

 if (temporary != NULL)
  {
   while (temporary != NULL)
    {
     printf(" %2d", temporary->value);
     temporary = temporary->next; 
    }
   printf("\n");
  }
}

node sort_list(node list)
{
 int number;
 node pointer1;
 node pointer2;

 pointer1 = list;
 pointer2 = list;

 while (pointer1->next != NULL)
  {
   pointer2 = pointer1;
   while (pointer2 != NULL)
    {
     if (pointer2->value < pointer1->value)
      {
       number = pointer2->value;
       pointer2->value = pointer1->value;
       pointer1->value = number;
      }
     pointer2 = pointer2->next;
    }
   pointer1 = pointer1->next;
  }

 return list;
}

node remove_pick(node list, int pick)
{
 node temporary;
 node remove;

 remove = list;
 temporary = list;

 if (remove != NULL)
  {
   while (remove->value != pick)
    {
     remove = remove->next;
    }
   if (temporary == remove)
    {
     temporary = temporary->next;
     free(remove);
     return temporary;
    }
   else
    {
     while (temporary->next != remove)
      {
       temporary = temporary->next;
      }
     temporary->next = remove->next;
     free(remove);
     return list;
    }
  }
}

void delete_list(node list)
{
 node temporary;

 temporary = list;

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
 int number;
 int used[N] = {0};
 int pick;
 node list;

 srand(time(NULL));

 list = NULL;

 // Create List
 printf("Creating List\n");
 for (i = 0; i < N; i++)
  {
   do
    {
     number = rand() % N;
    } while (used[number] == 1);
   list = append_list(list, number);
   used[number] = 1;
  }

 // Print List
 printf("Printing List\n");
 print_list(list);

 //Reverse List
 //Print List
 //Sort List
 printf("Sorting List\n");
 list = sort_list(list);

 //Print List
 printf("Printing List\n");
 print_list(list);

 //Remove Node
 pick = rand() % N;
 printf("Removing %d from the List\n", pick);
 list = remove_pick(list, pick);

 //Print List
 printf("Printing List\n");
 print_list(list);

 //Delete List
 printf("Deleting List\n");
 delete_list(list);

 return 0;
}
