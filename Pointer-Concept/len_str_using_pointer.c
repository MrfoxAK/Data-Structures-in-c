/**
 * C program to find length of a string using pointer
 */
#include <stdio.h>
int main()
{
     char s[50];
     int count = 0;
     printf("Enter the string : ");
     gets(s);
     char * ptr;
     ptr = s;
     while (*ptr != '\0')
     {
          count++;
          ptr++;
     }
     printf("The length of the string is : %d",count);
     return 0;
}


// #include <stdio.h>
// #define MAX_SIZE 100 // Maximum size of the string

// int main()
// {
//     char text[MAX_SIZE]; /* Declares a string of size 100 */
//     char * str = text; /* Declare pointer that points to text */
//     int count = 0;

//     /* Input string from user */
//     printf("Enter any string: ");
//     gets(text);

//     /* Iterate though last element of the string */
//     while(*(str++) != '\0') count++;

//     printf("Length of '%s' = %d", text, count);

//     return 0;
// }


// #include <stdio.h>
// int main()
// {
//      char s[50];
//      int i = 0, count = 0;
//      printf("Enter the string : ");
//      gets(s);
//      while (s[i] != '\0')
//      {
//           count++;
//           i++;
//      }
//      printf("The length of the string is : %d",count);
//      return 0;
// }