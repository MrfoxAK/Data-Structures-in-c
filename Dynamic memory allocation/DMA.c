#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *p;
    p = (int*)malloc(2*sizeof(int));
    printf("Enter the value ");
    scanf("%d",p+0);
    scanf("%d",p+1);
    printf("The value is : %d\n",*(p+0));
    printf("The value is : %d\n",*(p+1));
    return 0;
}