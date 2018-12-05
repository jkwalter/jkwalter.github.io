#include <stdio.h>
#include <time.h>
#include <string.h>

int main(void)
{
 int days;
 time_t current_date;
 time_t future_date;
 char* future_date_string;
 int length;

 current_date = time(NULL);

 do
  {
   printf("Enter the number of days from now: ");
   scanf("%d", &days);
  } while (days < 1);

 future_date = days * 24 * 60 * 60 + current_date;
 
 future_date_string = ctime(&future_date);
 length = strlen(future_date_string) - 1;
 future_date_string[length] = '\0';

 printf("%d days from now is %s.\n", days, future_date_string); 

 return 0;
}
