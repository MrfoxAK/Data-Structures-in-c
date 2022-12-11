#include <stdio.h>
int main()
{
     char s[] = "I am AK";
     char* p = s;
     char cpys[100];
     char * pt=cpys;
     // printf("%c",*(p+2));
     while (*p!='\0')
     {
          *(pt++) = *(p++);
          // printf("%c",*p);
     }
     *pt = '\0';
     printf("%s",cpys);
     return 0;
}