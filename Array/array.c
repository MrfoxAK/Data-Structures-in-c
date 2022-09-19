#include <stdio.h>
int main()
{
    int i, a[5];
    for (i = 0; i <= 4; i++)
    {
        printf("Enrter the %dth element of the arrray: ",i);
        scanf("%d", &a[i]);
    }
    for (int j = 0; j <= 4; j++)
    {
        printf("Now Printing %dth element of the array: ",j);
        printf("%d \n", a[j]);
    }
    return 0;
}





