/*
Compiling and Running in UNIX:

 - Open a terminal
 - Navigate to the same directory as hello.cpp
      cd ~/Documents/Programs/jkwalter.github.io/Software/C++
 - Type the following to compile hello.cpp
      g++ hello.cpp
 - Type the following to run hello.cpp
      ./a.out

Compiling and Running in Microsoft Visual Studio:

 - Open Developer Command Prompt for Visual Studio
 - Navigate to the same directory as hello.cpp
      cd "C:\Users\Josh Walter\Documents\Programs\C++"
 - Type the following to compile hello.cpp
      cl hello.cpp
 - Type the following to run hello.cpp
      hello
*/

#include <iostream>

using namespace std;

int main(void)
{
 cout << "Hello world!" << endl;

 return 0;
}
