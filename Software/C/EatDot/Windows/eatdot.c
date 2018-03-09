/*
Compiling and Running in Microsoft Visual Studio:

 - Open Developer Command Prompt for Visual Studio
 - Navigate to the same directory as eatdot.c
      cd "C:\Users\Josh Walter\Documents\Programs\C"
 - Type the following to compile eatdot.c
      cl eatdot.c
 - Type the following to run eatdot.c
      eatdot
 - Type one of the following maze files after the program starts
      maze1.txt
      maze2.txt
      maze3.txt
 - Use the arrow keys to move the character

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

void move_up(char maze[], int old_position)
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
  }
}

void move_down(char maze[], int old_position)
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
  }
}

void move_right(char maze[], int old_position)
{
 int new_position = old_position + 1;

 if (maze[new_position] != '|')
  {
   maze[new_position] = 'X';
   maze[old_position] = ' ';
  }
}

void move_left(char maze[], int old_position)
{
 int new_position = old_position - 1;

 if (maze[new_position] != '|')
  {
   maze[new_position] = 'X';
   maze[old_position] = ' ';
  }
}

int update_score(int score, int old_dots, int new_dots, int old_doubles, int new_doubles)
{
 int new_score;

 if (new_dots != old_dots)
  {
   new_score = score + 3;
  }
 if (new_doubles != old_doubles)
  {
   new_score = score * 2;
  }

 new_score--;

 return new_score;
}

void open_file(FILE *fp, char filename[], char maze[])
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

int find_character(char maze[], int length)
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

int find_dots(char maze[], int length)
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

int find_doubles(char maze[], int length)
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

void update(char maze[], int position)
{
 char movement;

 canonical_off();
 echo_off();

 movement = getchar();
 movement = getchar();
 movement = getchar();

 if (movement == 'A')
  {
   move_up(maze, position);
  }
 if (movement == 'B')
  {
   move_down(maze, position);
  }
 if (movement == 'C')
  {
   move_right(maze, position);
  }
 if (movement == 'D')
  {
   move_left(maze, position);
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
 int score = 0;
 int length = 0;
 int position = 0;
 int old_dots = 0;
 int new_dots = 0;
 int old_doubles = 0;
 int new_doubles = 0;
 int total = 0;

 system("cls");
 printf("Enter the file name: ");
 scanf("%s", filename);
 scanf("%c", &enter);

 open_file(fp, filename, maze);

 length = strlen(maze);

 old_dots = find_dots(maze, length);
 old_doubles = find_doubles(maze, length);
 total = old_dots + old_doubles;

 while (total != 0)
  {
   system("cls");
   printf("SCORE: %d\n", score);
   printf("\n");
   printf("%s\n", maze);
   position = find_character(maze, length);
   update(maze, position);
   new_dots = find_dots(maze, length);
   new_doubles = find_doubles(maze, length);
   score = update_score(score, old_dots, new_dots, old_doubles, new_doubles);
   old_dots = new_dots;
   old_doubles = new_doubles;
   total = old_dots + old_doubles;
  }

 system("cls");
 printf("SCORE: %d\n", score);
 printf("\n");
 printf("%s\n", maze);

 return 0;
}
