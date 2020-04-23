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

void move_up(char map[], int old_position)
{
	int newline = 0;
	int new_position = 0;

	while (map[newline] != '\n')
	{
		newline++;
	}

	newline++;
	new_position = old_position - newline;

	if (map[new_position] != '|')
	{
		map[new_position] = 'X';
		map[old_position] = ' ';
	}
}

void move_down(char map[], int old_position)
{
	int newline = 0;
	int new_position = 0;

	while (map[newline] != '\n')
	{
		newline++;
	}

	newline++;
	new_position = old_position + newline;

	if (map[new_position] != '|')
	{
		map[new_position] = 'X';
		map[old_position] = ' ';
	}
}

void move_right(char map[], int old_position)
{
	int new_position = old_position + 1;

	if (map[new_position] != '|')
	{
		map[new_position] = 'X';
		map[old_position] = ' ';
	}
}

void move_left(char map[], int old_position)
{
	int new_position = old_position - 1;

	if (map[new_position] != '|')
	{
		map[new_position] = 'X';
		map[old_position] = ' ';
	}
}

void update(char map[], int position)
{
	char movement;

	canonical_off();
	echo_off();

	movement = getchar();
	movement = getchar();
	movement = getchar();

	if (movement == 'A')
	{
		move_up(map, position);
	}
	if (movement == 'B')
	{
		move_down(map, position);
	}
	if (movement == 'C')
	{
		move_right(map, position);
	}
	if (movement == 'D')
	{
		move_left(map, position);
	}

	canonical_on();
	echo_on();
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

int find_position(char map[], int length)
{
	int i;
	int position = 0;

	for (i = 0; i < length; i++)
	{
		if (map[i] == 'X')
		{
			position = i;
		}
	}

	return position;
}

int main(void)
{
	FILE *fp;
	char filename[25] = {'\0'};
	char map[1000] = {'\0'};
	char enter;
	int length;
	int position;

	system("clear");
	printf("Enter the file name: ");
	scanf("%s", filename);
	scanf("%c", &enter);

	open_file(fp, filename, map);

	length = strlen(map);

	while (1 != 0)
	{
		system("clear");
		printf("%s\n", map);
		position = find_position(map, length);
		update(map, position);
	}

	return 0;
}
