#include <stdio.h>

int rev_num(int num){
     static int number=0;
     int r;
     if (num)
     {
          r=num%10;
          number=number*10+r;
          rev_num(num/10);
     }
     else
     {
          return 0;
     }
     return number;
}

int main()
{
     int num;
     printf("Enter the num: ");
     scanf("%d",&num);
     printf("Rev is %d",rev_num(num));
     return 0;
}