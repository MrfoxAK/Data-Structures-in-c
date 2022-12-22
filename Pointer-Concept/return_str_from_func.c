#include <stdio.h>

char* func(){
     // permanent

     return "AKASH";
}

char * s1111(){
     // heap area
     char * str = "AKasahhshajk";
     return str;
}

char* func1(){
     // stack memory 
     // char str[] = "AKASeweH";

     static char str[] = "AKASeweH";
     return str;
}

int * arr(){
     static int a[] = {1,2,55,44,33,44};
     // printf("%d ",*(a+2));
     return a;
}

int main()
{
     char *s;
     s=func();
     char *s1;
     s1=func1();
     printf("%s ",s);

     printf("%s ",s1);

     printf("%s ",s1111());
     int *ar = arr();
     for (int i = 0; i < 6; i++)
     {
          printf("%d ",*(ar+i));
     }
     
     return 0;
}