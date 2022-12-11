/**
 * C program to copy one string to another string using pointer
 */

#include <stdio.h>
int main()
{
     char s1[100],s2[100];
     printf("Enter the string : ");
     gets(s1);
     char *p1, *p2;
     p1 = s1;
     p2 = s2;
     while (*p1!='\0')
     {
          *p2 = *p1;
          p1++;
          p2++;
     }
     *p2 = '\0';
     printf("The copied String is : ");
     puts(s2);
     return 0;
}


// #include <stdio.h>
// #define MAX_SIZE 100 // Maximum size of the string

// int main()
// {
//     char text1[MAX_SIZE], text2[MAX_SIZE];
//     char * str1 = text1;
//     char * str2 = text2; 
    
//     /* Input string from user */
//     printf("Enter any string: ");
//     gets(text1);
    
//     /* Copy text1 to text2 character by character */
//     while(*(str2++) = *(str1++));

//     printf("First string = %s\n", text1);
//     printf("Second string = %s\n", text2);

//     return 0;
// }