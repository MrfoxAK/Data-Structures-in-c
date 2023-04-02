#include <stdio.h>

int power_of_a_num(int num, int power){
     if (power==0)
     {
          return 1;
     }
     return num*power_of_a_num(num,power-1);    
}

int main()
{
     int num = 5;
     int power = 2;
     printf("%d ",power_of_a_num(num,power));
     return 0;
}