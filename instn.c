#include <stdio.h>
int main()
{
    int i,j;
    int a[10] = {1, 44, 34, 4, 5, 56, 7};
    int size = 7;
    // printf("%d",size);
    int e = 25, index = 4;
    for ( i = size - 1; i >= index; i--)
    {
        a[i + 1] = a[i];
    }
    a[index] = e;
    size++;
    // printf("%d",a[5]);
    for ( j = 0; j < size; j++)
    {
        printf("Element at index %d is: %d\n",j,a[j]);
    }
    return 0;
}