/*
Compiling and Running in UNIX:

 - Open a terminal
 - Navigate to the same directory as scan.c
      cd ~/Documents/Programs/jkwalter.github.io/C
 - Type the following to compile scan.c
      gcc scan.c
 - Type the following to run scan.c
      ./a.out
*/

#include <stdio.h>
#include <string.h>

int count_characters(char phrase[], int length)
{
 int i;
 int characters;

 characters = 0;

 for (i = 0; i < length; i++)
  {
   characters++;
  }

 return characters;
}

int count_digits(char phrase[], int length)
{
 int i;
 int digits;

 digits = 0;

 for (i = 0; i < length; i++)
  {
   if (phrase[i] >= '0' && phrase[i] <= '9')
    {
     digits++;
    }
  }

 return digits;
}

int count_letters(char phrase[], int length)
{
 int i;
 int letters;

 letters = 0;

 for (i = 0; i < length; i++)
  {
   if (phrase[i] >= 'A' && phrase[i] <= 'Z')
    {
     letters++;
    }
   if (phrase[i] >= 'a' && phrase[i] <= 'z')
    {
     letters++;
    }
  }

 return letters;
}

int count_spaces(char phrase[], int length)
{
 int i;
 int spaces;

 spaces = 0;

 for (i = 0; i < length; i++)
  {
   if (phrase[i] == ' ')
    {
     spaces++;
    }
  }

 return spaces;
}

int count_symbols(char phrase[], int length)
{
 int i;
 int symbols;

 symbols = 0;

 for (i = 0; i < length; i++)
  {
   if (phrase[i] == '<')
    {
     symbols++;
    }
   if (phrase[i] == '>')
    {
     symbols++;
    }
   if (phrase[i] == '?')
    {
     symbols++;
    }
   if (phrase[i] == ',')
    {
     symbols++;
    }
   if (phrase[i] == '.')
    {
     symbols++;
    }
   if (phrase[i] == '/')
    {
     symbols++;
    }
   if (phrase[i] == '`')
    {
     symbols++;
    }
   if (phrase[i] == '~')
    {
     symbols++;
    }
   if (phrase[i] == '!')
    {
     symbols++;
    }
   if (phrase[i] == '@')
    {
     symbols++;
    }
   if (phrase[i] == '#')
    {
     symbols++;
    }
   if (phrase[i] == '$')
    {
     symbols++;
    }
   if (phrase[i] == '%')
    {
     symbols++;
    }
   if (phrase[i] == '^')
    {
     symbols++;
    }
   if (phrase[i] == '&')
    {
     symbols++;
    }
   if (phrase[i] == '*')
    {
     symbols++;
    }
   if (phrase[i] == '(')
    {
     symbols++;
    }
   if (phrase[i] == ')')
    {
     symbols++;
    }
   if (phrase[i] == '_')
    {
     symbols++;
    }
   if (phrase[i] == '-')
    {
     symbols++;
    }
   if (phrase[i] == '+')
    {
     symbols++;
    }
   if (phrase[i] == '=')
    {
     symbols++;
    }
   if (phrase[i] == '{')
    {
     symbols++;
    }
   if (phrase[i] == '}')
    {
     symbols++;
    }
   if (phrase[i] == '[')
    {
     symbols++;
    }
   if (phrase[i] == ']')
    {
     symbols++;
    }
   if (phrase[i] == '|')
    {
     symbols++;
    }
   if (phrase[i] == '\\')
    {
     symbols++;
    }
   if (phrase[i] == ':')
    {
     symbols++;
    }
   if (phrase[i] == ';')
    {
     symbols++;
    }
   if (phrase[i] == '"')
    {
     symbols++;
    }
   if (phrase[i] == '\'')
    {
     symbols++;
    }
  }

 return symbols;
}

int count_sequence(char phrase[], int length)
{
 int i;
 int max;
 int sequence;

 max = 0;
 sequence = 0;

 for (i = 0; i < length; i++)
  {
   if (phrase[i] == '@')
    {
     sequence++;
    }
   else
    {
     if (max < sequence)
      {
       max = sequence;
      }
     sequence = 0;
    }
  }

 return max;
}

int main(void)
{
 int i;
 int length;
 int characters;
 int digits;
 int letters;
 int spaces;
 int symbols;
 int sequence;
 char phrase[1024];

 printf("Type in a phrase: ");
 fgets(phrase, 1024, stdin);
 printf("\n");
 printf("Phrase: - %s -\n", phrase);

 length = strlen(phrase);

 printf("\n");
 printf("Removing '\\n' from phrase.\n");
 length--;
 phrase[length] = '\0';

 printf("\n");
 printf("Phrase: - %s -\n", phrase);

 printf("\n");
 for (i = 0; i < length; i++)
  {
   printf(" %4d: %c\n", i, phrase[i]);
  }

 characters = count_characters(phrase, length);
 digits = count_digits(phrase, length);
 letters = count_letters(phrase, length);
 spaces = count_spaces(phrase, length);
 symbols = count_symbols(phrase, length);
 sequence = count_sequence(phrase, length);

 printf("\n");
 printf("Number of characters: %d\n", characters);
 printf("Number of digits: %d\n", digits);
 printf("Number of letters: %d\n", letters);
 printf("Number of spaces: %d\n", spaces);
 printf("Number of symbols: %d\n", symbols);
 printf("Length of longest '@' sequence: %d\n", sequence);

 return 0;
}
