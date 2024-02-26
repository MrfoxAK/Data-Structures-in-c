#include <stdio.h>
#include <stdlib.h>

struct node
{
     int f;
     int r;
     int * arr;
};


int main()
{
     struct node s1,s2;
     s1.f = 11;
     s1.r = 23;
     s2.f = 5;
     s2.r = 55;
     s1.arr = (int*)malloc(5*sizeof(int));
     s1.arr[0] = 1; // Fill the array with some values
     s1.arr[1] = 2;
     s1.arr[2] = 3;
     s1.arr[3] = 4;
     s1.arr[4] = 5;

     // Print the first element of the array
     // printf("%d\n", s1.arr[4]);

     // Free the allocated memory
     free(s1.arr);

     int s[10];
     s[0] = 11;
     s[1] = 22;
     int * p = s;
     printf("%d\n",*p+1);
     printf("%d\n",*(p+1));
     return 0;
}