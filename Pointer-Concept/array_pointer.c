#include<stdio.h>
int main()
{
    // int a = 34;
    // int* ptra = &a;
    // printf("%d\n",ptra);
    // ptra++;
    // printf("%d\n",ptra);
    // printf("%d\n",ptra-1);

    // arr[i] = arr + i;
    int arr[] = {1,2,3,4,5,6,7};
    int* arrayptr = arr;
    printf("Value at position 3 of the array is %d\n",arr[2]);
    printf("The address of 1st element the array is %d\n",&arr[0]);
    printf("The address of 1st element the array is %d\n",arr);
    printf("The address of 2nd element the array is %d\n",&arr[1]);
    printf("The address of 2nd element the array is %d\n",arr +1);


    printf("The value at address of 1st element the array is %d\n",*(&arr[0]));
    printf("The value at address of 1st element the array is %d\n",*arr);
    printf("The value at address of 2nd element the array is %d\n",*(&arr[1]));
    printf("The value at address of 2nd element the array is %d\n",*(arr +1));
    arrayptr++;
    return 0;
}
