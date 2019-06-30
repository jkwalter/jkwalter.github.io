/*
Compiling and Running in UNIX:

 - Open a terminal
 - Navigate to the same directory as double_linklist.c
      cd ~/Documents/Programs/jkwalter.github.io/Software/C
 - Type the following to compile double_linklist.c
      gcc double_linklist.c
 - Type the following to run double_linklist.c
      ./a.out

Compiling and Running in Microsoft Visual Studio:

 - Open Developer Command Prompt for Visual Studio
 - Navigate to the same directory as double_linklist.c
      cd "C:\Users\Josh Walter\Documents\Programs\C"
 - Type the following to compile double_linklist.c
      cl double_linklist.c
 - Type the following to run double_linklist.c
      double_linklist
*/

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

node append_list(node list, int value)
{
 node temporary;
 node create;

 if (list == NULL)
  {
   create = malloc(sizeof(node));
   create->number = value;
   create->next = NULL;
   create->previous = NULL;

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

node assign_back(node list)
{
 node temporary;

 if (list != NULL)
  {
   temporary = list;
   while (temporary->next != NULL)
    {
     temporary = temporary->next;
    }
   return temporary;
  }
}

void print_list(node list)
{
 node temporary;

 if (list != NULL)
  {
   temporary = list;
   if (list->next != NULL)
    {
     printf("Printing list in normal order.\n");
     while (temporary != NULL)
      {
       printf(" %d", temporary->number);
       temporary = temporary->next;
      }
    }
   else
    {
     printf("Printing list in reverse order.\n");
     while (temporary != NULL)
      {
       printf(" %d", temporary->number);
       temporary = temporary->previous;
      }
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
   printf("Removing %d from the list.\n", pick);
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
   printf("Deleting list.\n");
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
 node front;
 node back;

 srand(time(NULL));

 front = NULL;
 back = NULL;

 printf("Creating a list of %d numbers.\n", N);
 for (i = 0; i < N; i++)
  {
   do
    {
     value = rand() % N;
    } while (used[value] == 1);
   used[value] = 1;
   front = append_list(front, value);
  }
 back = assign_back(front);
 printf("List created.\n");

 print_list(front);
 print_list(back);
 pick = rand() % N;
 front = remove_pick(front, pick);
 print_list(front);
 print_list(back);
 delete_list(front);

 return 0;
}
