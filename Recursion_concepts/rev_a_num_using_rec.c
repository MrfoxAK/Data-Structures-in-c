#include <stdio.h>

int rev_num(int num){
     static int n = 0;
     n = n*10+num%10;
     if (num<10)
     {
          return n;
     }
     rev_num(num/10);
}

int main()
{
     int num;
     printf("Enter the Num : ");
     scanf("%d",&num);
     printf("%d",rev_num(num));
     return 0;
}