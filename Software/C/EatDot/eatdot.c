/*
Compiling and Running in UNIX:

 - Open a terminal
 - Navigate to the same directory as eatdot.c
      cd ~/Programs/jkwalter.github.io/Software/C/EatDot
 - Type the following to complie eatdot.c
      gcc eatdot.c
 - Type the following to run eatdot.c
      ./a.out
 - Type one of the following maze files after the program starts
      maze1.txt
      maze2.txt
      maze3.txt
 - Use the arrow keys to move the character

NOTE: eatdot.c only works with Bash shell
NOTE: Maze files and eatdot.c must be in the same directory
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

void canonical_off(void)
{
 struct termios settings;

 tcgetattr(STDIN_FILENO, &settings);
 settings.c_lflag &= ~ICANON;
 tcsetattr(STDIN_FILENO, TCSANOW, &settings);
}

void echo_off(void)
{
 struct termios settings;

 tcgetattr(STDIN_FILENO, &settings);
 settings.c_lflag &= ~ECHO;
 tcsetattr(STDIN_FILENO, TCSANOW, &settings);
}

void canonical_on(void)
{
 struct termios settings;

 tcgetattr(STDIN_FILENO, &settings);
 settings.c_lflag |= ICANON;
 tcsetattr(STDIN_FILENO, TCSANOW, &settings);
}

void echo_on(void)
{
 struct termios settings;

 tcgetattr(STDIN_FILENO, &settings);
 settings.c_lflag |= ECHO;
 tcsetattr(STDIN_FILENO, TCSANOW, &settings);
}

void moveUp(char maze[], int old_position)
{
 int newline = 0;
 int new_position = 0;

 while (maze[newline] != '\n')
  {
   newline++;
  }

 newline++;
 new_position = old_position - newline;

 if (maze[new_position] != '|')
  {
   maze[new_position] = 'X';
   maze[old_position] = ' ';
   old_position = new_position;
  }
 else
  {
   new_position = old_position;
  }
}

void moveDown(char maze[], int old_position)
{
 int newline = 0;
 int new_position = 0;

 while (maze[newline] != '\n')
  {
   newline++;
  }

 newline++;
 new_position = old_position + newline;

 if (maze[new_position] != '|')
  {
   maze[new_position] = 'X';
   maze[old_position] = ' ';
   old_position = new_position;
  }
 else
  {
   new_position = old_position;
  }
}

void moveRight(char maze[], int old_position)
{
 int new_position = old_position + 1;

 if (maze[new_position] != '|')
  {
   maze[new_position] = 'X';
   maze[old_position] = ' ';
   old_position = new_position;
  }
 else
  {
   new_position = old_position;
  }
}

void moveLeft(char maze[], int old_position)
{
 int new_position = old_position - 1;

 if (maze[new_position] != '|')
  {
   maze[new_position] = 'X';
   maze[old_position] = ' ';
   old_position = new_position;
  }
 else
  {
   new_position = old_position;
  }
}

int updateScore(int score, int old_dots, int new_dots, int old_doubles, int new_doubles)
{
 if (new_dots != old_dots)
  {
   score = score + 3;
  }
 if (new_doubles != old_doubles)
  {
   score = score * 2;
  }

 score--;

 return score;
}

void openFile(FILE *fp, char filename[], char maze[])
{
 int i;

 fp = fopen(filename, "r");

 if (fp == NULL)
  {
   printf("ERROR: Unable to open file.\n");
   exit(1);
  }

 for (i = 0; i < 1000; i++)
  {
   fscanf(fp, "%c", &maze[i]);
  }

 fclose(fp);
}

int findCharacter(char maze[], int length)
{
 int i;
 int position = 0;

 for (i = 0; i < length; i++)
  {
   if (maze[i] == 'X')
    {
     position = i;
    }
  }

 return position;
}

int findDots(char maze[], int length)
{
 int i;
 int dots = 0;

 for (i = 0; i < length; i++)
  {
   if (maze[i] == '.')
    {
     dots++;
    }
  }

 return dots;
}

int findDoubles(char maze[], int length)
{
 int i;
 int doubles = 0;

 for (i = 0; i < length; i++)
  {
   if (maze[i] == 'o')
    {
     doubles++;
    }
  }

 return doubles;
}

void update(char maze[], char movement, int position)
{
 canonical_off();
 echo_off();

 movement = getchar();
 movement = getchar();
 movement = getchar();

 if (movement == 'A')
  {
   moveUp(maze, position);
  }
 if (movement == 'B')
  {
   moveDown(maze, position);
  }
 if (movement == 'C')
  {
   moveRight(maze, position);
  }
 if (movement == 'D')
  {
   moveLeft(maze, position);
  }

 canonical_on();
 echo_on();
}

int main(void)
{
 FILE *fp;
 char filename[25] = {'\0'};
 char maze[1000] = {'\0'};
 char enter;
 char movement;
 int score = 0;
 int length = 0;
 int position = 0;
 int old_dots = 0;
 int new_dots = 0;
 int old_doubles = 0;
 int new_doubles = 0;
 int total = 0;

 system("clear");
 printf("Enter the file name: ");
 scanf("%s", filename);
 scanf("%c", &enter);

 openFile(fp, filename, maze);

 length = strlen(maze);

 old_dots = findDots(maze, length);
 old_doubles = findDoubles(maze, length);
 total = old_dots + old_doubles;

 while (total != 0)
  {
   system("clear");
   printf("SCORE: %d\n", score);
   printf("\n");
   printf("%s\n", maze);
   position = findCharacter(maze, length);
   update(maze, movement, position);
   new_dots = findDots(maze, length);
   new_doubles = findDoubles(maze, length);
   score = updateScore(score, old_dots, new_dots, old_doubles, new_doubles);
   old_dots = new_dots;
   old_doubles = new_doubles;
   total = old_dots + old_doubles;
  }

 system("clear");
 printf("SCORE: %d\n", score);
 printf("\n");
 printf("%s\n", maze);

 return 0;
}
