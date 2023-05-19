#include <stdio.h>
#include <stdlib.h>
int main()
{
     int size;
     int *ptr;
     printf("Enter the size : ");
     scanf("%d",&size);
     ptr = (int*)malloc(size*sizeof(int));
     for (int i = 0; i < size; i++)
     {
          printf("Enter at %d: ",i);
          scanf("%d",&ptr[i]);
     }
     for (int i = 0; i < size; i++)
     {
          printf("%d ",ptr[i]);
     }
     return 0;
}