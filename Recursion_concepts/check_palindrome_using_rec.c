#include <stdio.h>

int rev_num(int num)
{
     static int n = 0;
     n = n * 10 + num % 10;
     if (num < 10)
     {
          return n;
     }
     rev_num(num / 10);
}

int ifPalindrome(int num)
{
     if (num == rev_num(num))
     {
          return 1;
     }
     else{
          return 0;
     }
}

int main()
{
     int num;
     printf("Enter the Num : ");
     scanf("%d", &num);
     if (ifPalindrome(num))
     {
          printf("Yes It's Palindrome\n");
     }
     else
     {
          printf("No It's not Palindrome\n");
     }
     return 0;
}