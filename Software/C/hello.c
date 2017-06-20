/*
Compiling and Running in UNIX:

 - Open a terminal
 - Navigate to the same directory as hello.c
      cd ~/Programs/jkwalter.github.io/Software/C
 - Type the following to complie hello.c
      gcc hello.c
 - Type the following to run hello.c
      ./a.out

Compiling and Running in Microsoft Visual Studio:

 - Open Developer Command Prompt for Visual Studio
 - Navigate to the same directory as hello.c
      cd C:\Users\Josh\Documents\Programs\C
 - Type the following to compile hello.c
      cl hello.c
 - Type the following to run hello.c
      hello.exe
*/

#include <stdio.h>

int main(void)
{
 printf("Hello world!\n");

 return 0;
}
