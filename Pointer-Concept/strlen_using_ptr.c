#include <stdio.h>
int main()
{
     char s[] = "Akash";
     int len=0;
     char * ptr = s;
     while ((*ptr)!='\0')
     {
          len++;
          ptr++;
     }
     printf("The len is %d",len);
     return 0;
}