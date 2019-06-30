#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
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

void check(char map[], int location, int collection[])
{
 if (map[location] == '5')
  {
   collection[5] = 1;
  }
 if (map[location] == '4')
  {
   collection[4] = 1;
  }
 if (map[location] == '3')
  {
   collection[3] = 1;
  }
 if (map[location] == '2')
  {
   collection[2] = 1;
  }
 if (map[location] == '1')
  {
   collection[1] = 1;
  }
}

void move_up(char map[], int old_location, int collection[])
{
 int newline = 0;
 int new_location = 0;

 while (map[newline] != '\n')
  {
   newline++;
  }

 newline++;
 new_location = old_location - newline;

 if (map[new_location] != '|')
  {
   check(map, new_location, collection);
   map[new_location] = 'X';
   map[old_location] = ' ';
  }
}

void move_down(char map[], int old_location, int collection[])
{
 int newline = 0;
 int new_location = 0;

 while (map[newline] != '\n')
  {
   newline++;
  }

 newline++;
 new_location = old_location + newline;

 if (map[new_location] != '|')
  {
   check(map, new_location, collection);
   map[new_location] = 'X';
   map[old_location] = ' ';
  }
}

void move_right(char map[], int old_location, int collection[])
{
 int new_location = old_location + 1;

 if (map[new_location] != '|')
  {
   check(map, new_location, collection);
   map[new_location] = 'X';
   map[old_location] = ' ';
  }
}

void move_left(char map[], int old_location, int collection[])
{
 int new_location = old_location - 1;

 if (map[new_location] != '|')
  {
   check(map, new_location, collection);
   map[new_location] = 'X';
   map[old_location] = ' ';
  }
}

void open_file(FILE *fp, char filename[], char map[])
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
   fscanf(fp, "%c", &map[i]);
  }

 fclose(fp);
}

int find_character(char map[], int length)
{
 int i;
 int location = 0;

 for (i = 0; i < length; i++)
  {
   if (map[i] == 'X')
    {
     location = i;
    }
  }

 return location;
}

int update(char map[], int location, int collection[])
{
 char movement;

 canonical_off();
 echo_off();

 movement = getchar();
 movement = getchar();
 movement = getchar();

 if (movement == 'A')
  {
   move_up(map, location, collection);
  }
 if (movement == 'B')
  {
   move_down(map, location, collection);
  }
 if (movement == 'C')
  {
   move_right(map, location, collection);
  }
 if (movement == 'D')
  {
   move_left(map, location, collection);
  }

 canonical_on();
 echo_on();
}

int main(void)
{
 FILE *fp;
 char filename[25] = {'\0'};
 char map[1000] = {'\0'};
 char enter;
 int i;
 int length;
 int number_position;
 int character_position;
 int remaining = 5;
 int order = 0;
 int collection[6] = {0};

 srand(time(NULL));

 system("clear");
 printf("Enter the file name: ");
 scanf("%s", filename);
 scanf("%c", &enter);

 open_file(fp, filename, map);

 length = strlen(map);

 for (i = 0; i < 5; i++)
  {
   do
    {
     number_position = rand() % length;
    } while (map[number_position] != ' ');
   map[number_position] = i + '1';
  }

 while (remaining != 0 && order == 0)
  {
   system("clear");
   printf("COLLECT THE NUMBERS IN DESCENDING ORDER!\n");
   printf("\n");
   printf("%s\n", map);
   character_position = find_character(map, length);
   update(map, character_position, collection);
   if (collection[remaining] == 1)
    {
     remaining--;
    }
   for (i = remaining; i > 0; i--)
    {
     if (collection[i] == 1)
      {
       order++;
      }
    }
  }

 system("clear");
 printf("COLLECT THE NUMBERS IN DESCENDING ORDER!\n");
 printf("\n");
 printf("%s\n", map);
 printf("\n");

 if (order == 0)
  {
   printf("YOU WON!\n");
  }
 else
  {
   printf("YOU LOST!\n");
  }

 return 0;
}
