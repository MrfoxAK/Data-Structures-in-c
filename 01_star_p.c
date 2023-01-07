// Floyd's Triangle
#include <stdio.h>
int main()
{
    int n, a, b;
    printf("Enter the no.of rows: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            a = 1;
            b = 0;
        }
        else
        {
            a = 0;
            b = 1;
        }
        for (int j = 1; j <= i; j++)
        {
            if (j%2==0)
            {
                printf("%d",a);
            }
            else
            {
                printf("%d",b);
            }
        }
        printf("\n");
    }
    return 0;
}
