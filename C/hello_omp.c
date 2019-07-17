/*
Compiling and Running in UNIX:

 - Open a terminal
 - Navigate to the same directory as hello_omp.c
      cd ~/Documents/Programs/jkwalter.github.io/C
 - Type the following to compile hello_omp.c
      gcc hello_omp.c -fopenmp
 - Type the following to run hello_omp.c
      ./a.out
*/

#include <stdio.h>
#include <omp.h>

int main(void)
{
 int i;
 int id;

 #pragma omp parallel for private(id)
 for (i = 0; i < 5; i++)
  {
   id = omp_get_thread_num();
   printf("Hello from Thread %d!\n", id);
  }

 return 0;
}
