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
 int new_score = score;

 if (new_dots != old_dots)
  {
   new_score = new_score + 3;
  }
 if (new_doubles != old_doubles)
  {
   new_score = new_score * 2;
  }

 new_score--;

 printf("SCORE: %d\n", new_score);
 printf("\n");

 return new_score;
}

void openFile(FILE *fp, char filename[], char maze[], int i)
{
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

int findLength(char maze[])
{
 int length = 0;

 length = strlen(maze);

 return length;
}

int findCharacter(int i, char maze[], int length)
{
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

int findDots(int i, char maze[], int length)
{
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

int findDoubles(int i, char maze[], int length)
{
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

void update(char maze[], char movement, int position, char enter)
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
 int i;
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
 enter = getchar();

 system("clear");

 openFile(fp, filename, maze, i);

 printf("SCORE: %d\n", score);
 printf("\n");

 printf("%s", maze);
 printf("\n");

 length = findLength(maze);
 position = findCharacter(i, maze, length);
 new_dots = findDots(i, maze, length);
 new_doubles = findDoubles(i, maze, length);
 old_dots = new_dots;
 old_doubles = new_doubles;
 total = old_dots + old_doubles;

 while (total != 0)
  {
   update(maze, movement, position, enter);
   position = findCharacter(i, maze, length);
   new_dots = findDots(i, maze, length);
   new_doubles = findDoubles(i, maze, length);
   system("clear");
   score = updateScore(score, old_dots, new_dots, old_doubles, new_doubles);
   printf("%s", maze);
   old_dots = new_dots;
   old_doubles = new_doubles;
   total = old_dots + old_doubles;
  }

 return 0;
}
