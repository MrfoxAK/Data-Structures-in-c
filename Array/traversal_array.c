#include <stdio.h>

void display(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",arr[i]);
    }
}

int main()
{
    int n;
    int arr[] = { 2, -1, 5, 6, 0, -3 };
    n = sizeof(arr)/sizeof(int);
    display(arr, n);
    return 0;
}









// // writing a program in C to perform traverse operation on an array
  
// void main()
// {
//     int i, size;
//     int arr[]={1, -9, 17, 4, -3};     //declaring and initializing array
//     size=sizeof(arr)/sizeof(arr[0]);     //sizeof(arr) will give 20 and sizeof(arr[0]) will give 4
//     printf("The array elements are: ");
//     for(i=0;i<size;i++)
//         printf("\narr[%d]= %d", i, arr[i]);
// }