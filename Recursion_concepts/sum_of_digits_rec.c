#include <stdio.h>

int sum_of_digit(int num){
     static int sum=0;
     if (num==0)
     {
          return 0;
     }
     // while (num)
     // {
     sum=sum+num%10;
     // }
     sum_of_digit(num/10);
     return sum;
}

int main()
{
     int num;
     /* Input any number from user */
     printf("Enter any number: ");
     scanf("%d", &num);
     printf("The sum is %d",sum_of_digit(num));
     return 0;
}