/*
Compiling and Running in UNIX:

 - Open a terminal
 - Navigate to the same directory as linklist.cpp
      cd ~/Documents/Programs/jkwalter.github.io/C++
 - Type the following to compile linklist.cpp
      g++ linklist.cpp
 - Type the following to run linklist.cpp
      ./a.out
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

#define N 10

using namespace std;

struct node
{
 int value;
 node *next;
 node *previous;
};

class linklist
{
 private:
  node *head;
  node *tail;
 public:
  linklist(void);
  void set_head(int number);
  void set_tail(void);
  void print_head(void);
  void print_tail(void);
  void sort_linklist(void);
  void remove_pick(int pick);
  void delete_linklist(void);
};

linklist::linklist(void)
{
 head = NULL;
 tail = NULL;
}

void linklist::set_head(int number)
{
 node *temporary;
 node *create;

 temporary = head;

 if (head == NULL)
  {
   head = new node;
   head->value = number;
   head->next = NULL;
   head->previous = NULL;
  }
 else
  {
   while (temporary->next != NULL)
    {
     temporary = temporary->next;
    }
   create = new node;
   create->value = number;
   create->next = temporary->next;
   temporary->next = create;
   create->previous = temporary;
  }
}

void linklist::set_tail(void)
{
 node *temporary;

 temporary = head;

 if (temporary != NULL)
  {
   while (temporary->next != NULL)
    {
     temporary = temporary->next;
    }
   tail = temporary;
  }
}

void linklist::print_head(void)
{
 node *temporary;

 temporary = head;

 if (temporary != NULL)
  {
   while (temporary != NULL)
    {
     cout << " " << temporary->value;
     temporary = temporary->next;
    }
   cout << endl;
  }
}

void linklist::print_tail(void)
{
 node *temporary;

 temporary = tail;

 if (temporary != NULL)
  {
   while (temporary != NULL)
    {
     cout << " " << temporary->value;
     temporary = temporary->previous;
    }
   cout << endl;
  }
}

void linklist::sort_linklist(void)
{
 node *sort1;
 node *sort2;
 int temporary;

 sort1 = head;

 if (sort1 != NULL)
  {
   while (sort1->next != NULL)
    {
     sort2 = sort1->next;
     while (sort2 != NULL)
      {
       if (sort2->value < sort1->value)
        {
         temporary = sort2->value;
         sort2->value = sort1->value;
         sort1->value = temporary;
        }
       sort2 = sort2->next;
      }
     sort1 = sort1->next;
    }
  }
}

void linklist::remove_pick(int pick)
{
 node *remove;
 node *temporary;

 remove = head;

 if (remove != NULL)
  {
   while (remove->value != pick)
    {
     remove = remove->next;
    }
   if (remove == head)
    {
     head = remove->next;
     head->previous = remove->previous;
    }
   else
    {
     temporary = head;
     while (temporary->next != remove)
      {
       temporary = temporary->next;
      }
     temporary->next = remove->next;
     if (temporary->next != NULL)
      {
       temporary = temporary->next;
       temporary->previous = remove->previous;
      }
    }
   delete remove;
  } 
}

void linklist::delete_linklist(void)
{
 node *temporary;

 if (head != NULL)
  {
   while (head != NULL)
    {
     temporary = head;
     head = head->next;
     delete temporary;
    }
  }
}

int main(void)
{
 int i;
 int number;
 int used[N] = {0};
 int pick;
 linklist list;

 srand(time(NULL));

 cout << "Creating List" << endl;
 for (i = 0; i < N; i++)
  {
   do
    {
     number = rand() % N;
    } while (used[number] == 1);
   used[number] = 1;
   list.set_head(number);
  }

 list.set_tail();

 cout << "Printing List Forwards" << endl;
 list.print_head();
 cout << "Printing List Backwards" << endl;
 list.print_tail();

 cout << "Sorting List" << endl;
 list.sort_linklist();

 cout << "Printing List Forwards" << endl;
 list.print_head();
 cout << "Printing List Backwards" << endl;
 list.print_tail();

 pick = rand() % N;
 cout << "Removing " << pick << " from List" << endl;
 list.remove_pick(pick);

 list.set_tail();

 cout << "Printing List Forwards" << endl;
 list.print_head();
 cout << "Printing List Backwards" << endl;
 list.print_tail();

 cout << "Deleting List" << endl;
 list.delete_linklist();

 return 0;
}
