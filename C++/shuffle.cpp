/*
Compiling and Running in UNIX:

 - Open a terminal
 - Navigate to the same directory as shuffle.cpp
      cd ~/Documents/Programs/jkwalter.github.io/C++
 - Type the following to compile shuffle.cpp
      g++ shuffle.cpp
 - Type the following to run shuffle.cpp
      ./a.out
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

#define N 10

using namespace std;

struct node
{
 int number;
 int shuffle;
 node *next;
};

class queue
{
 private:
  node *head;
 public:
  queue(void);
  void append_list(int order, int random);
  void print_list(void);
  void shuffle_list(void);
  void delete_list(void);
};

queue::queue(void)
{
 head = NULL;
}

void queue::append_list(int order, int random)
{
 node *front;
 node *create;

 front = head;

 if (head == NULL)
  {
   create = new node;
   create->number = order;
   create->shuffle = random;
   create->next = head;
   head = create;
  }
 else
  {
   while (front->next != NULL)
    {
     front = front->next;
    }
   create = new node;
   create->number = order;
   create->shuffle = random;
   create->next = front->next;
   front->next = create;
  }
}

void queue::print_list(void)
{
 node *print;

 print = head;

 if (print != NULL)
  {
   cout << "NORMAL     RANDOM" <<  endl;
   while (print != NULL)
    {
     cout << "  " << print->number << "           " << print->shuffle << endl;
     print = print->next;
    }
  }
}

void queue::shuffle_list(void)
{
 node *i;
 node *j;
 int value;
 int random;

 i = head;

 if (i != NULL)
  {
   while (i->next != NULL)
    {
     j = i->next;
     while (j != NULL)
      {
       if (j->shuffle < i->shuffle)
        {
         value = j->number;
         random = j->shuffle;
         j->number = i->number;
         j->shuffle = i->shuffle;
         i->number = value;
         i->shuffle = random;
        }
       j = j->next;
      }
     i = i->next;
    }
  }
}

void queue::delete_list(void)
{
 node *remove;

 if (head != NULL)
  {
   while (head != NULL)
    {
     remove = head;
     head = head->next;
     delete remove;
    }
  }
}

int main(void)
{
 int i;
 int r;
 int used[N] = {0};
 queue list;

 srand(time(NULL));

 for (i = 0; i < N; i++)
  {
   do
    {
      r = rand() % N;
    } while (used[r] != 0);
   list.append_list(i, r);
   used[r] = 1;
  }

 list.print_list();
 list.shuffle_list();
 list.print_list();
 list.delete_list();

 return 0;
}
