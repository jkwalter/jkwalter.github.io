/*
Compiling and Running in Linux:

 - Open a terminal
 - Navigate to the same directory as queue.c
 - Type the following to complie queue.c
      gcc queue.c
 - Type the following to run queue.c
      ./a.out
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct queue *node;

struct queue
{
 int value;
 node next;
};

node enqueue(node list, int number)
{
 node tmp;

 tmp = malloc(sizeof(node));
 tmp->value = number;
 tmp->next = list;

 printf("\n");
 printf("%d was successfully put on the queue.\n", tmp->value);

 return tmp;
}

node dequeue(node list)
{
 int number;
 node tmp;
 node remove;

 tmp = list;
 remove = list;

 while (remove->next != NULL)
  {
   remove = remove->next;
  }

 while (tmp->next != remove)
  {
   tmp = tmp->next;
  }

 number = remove->value;
 tmp->next = remove->next;
 free(remove);

 printf("%d was successfully removed from the queue.\n", number);

 return list;
}

void view(node list, int size)
{
 node tmp;
 
 tmp = list;

 while (tmp != NULL)
  {
   printf("Node %2d: %d\n", size, tmp->value);
   tmp = tmp->next;
   size--;
  }
}

void dequeue_all(node list)
{
 node tmp;

 if (list != NULL)
  {
   while (list != NULL)
    {
     tmp = list;
     list = list->next;
     free(tmp);
    }
  }
}

int main(void)
{
 int option;
 int number;
 int item;
 int size;
 char enter;
 char key;
 node list;

 list = NULL;
 size = 0;

 do
  {
   system("clear");
   printf("==============================\n");
   printf("     QUEUE IMPLEMENTATION\n");
   printf("==============================\n");
   printf("\n");
   printf("          MAIN MENU\n");
   printf("\n");
   printf("1: Put a number on the queue\n");
   printf("2: Remove a number from the queue\n");
   printf("3: View the queue\n");
   printf("4: Exit\n");
   printf("\n");
   printf("Enter your option here (1-4): ");
   scanf("%d", &option);
   scanf("%c", &enter);
   switch (option)
    {
     case 1:
            system("clear");
            if (size == 10)
             {
              printf("Queue is full!\n");
              printf("Please remove a number from the queue to continue.\n");
              printf("Enter any key to return to the main menu: ");
              scanf("%c", &key);
              scanf("%c", &enter);
             }
            else
             {
              printf("Enter a number to put on the queue: ");
              scanf("%d", &number);
              scanf("%c", &enter);
              list = enqueue(list, number);
              size++;
              printf("Enter any key to return to the main menu: ");
              scanf("%c", &key);
              scanf("%c", &enter);
             }
            break;
     case 2:
            system("clear");
            if (list == NULL)
             {
              printf("Queue is empty!\n");
              printf("Please put a number on the queue to continue.\n");
              printf("Enter any key to return to the main menu: ");
              scanf("%c", &key);
              scanf("%c", &enter);
             }
            else
             {
              list = dequeue(list);
              size--;
              printf("Enter any key to return to the main menu: ");
              scanf("%c", &key);
              scanf("%c", &enter);
             }
            break;
     case 3:
            system("clear");
            if (list == NULL)
             {
              printf("Queue is empty!\n");
              printf("Please put a number on the queue to continue.\n");
              printf("Enter any key to return to the main menu: ");
              scanf("%c", &key);
              scanf("%c", &enter);
             }
            else
             {
              view(list, size);
              printf("\n"); 
              printf("Enter any key to return to the main menu: ");
              scanf("%c", &key);
              scanf("%c", &enter);
             }
            break;
     case 4:
            break;
    }
  } while (option != 4);

 system("clear");
 printf("Removing all numbers from the queue.\n");
 dequeue_all(list);
 printf("All numbers have been removed from the queue.\n");

 return 0;
}
