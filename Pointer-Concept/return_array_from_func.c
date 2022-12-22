#include <stdio.h>

/**
 * Function to return an array using pointers.
 * @return 	Pointer to array
 */
int *getArray()
{
     // int num[] = {1, 2, 3, 4, 5};
     // we have to make it static
     static int num[] = {1, 2, 3, 4, 5};
     int i;

     printf("Array inside function: ");
     // Print value of each array element
     for (i = 0; i < 5; ++i)
     {
          printf("%d\n", num[i]);
     }

     return num;
}

int main()
{
     int i;

     // Pointer to store array
     int *num;

     // Call getArray function to get pointer to array
     num = getArray();

     printf("Array outside function: \n");
     // Print value of each array element
     for (i = 0; i < 5; ++i)
     {
          printf("%d\n", num[i]);
     }

     return 0;
}