#include <stdio.h>


//Traversal
void display(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",arr[i]);
    }
    
}


// Deletion
void indDeletion(int arr[], int size, int index ){
    // if (index>=capacity)
    // {
    //     return -1;
    // }
    for (int i = index; i < size-1; i++)
    {
        arr[i] = arr[i+1];
    }
}


int main()
{
    int size=6, index = 4;
    int arr[100] = {1,2,3,4,5,6};
    // display(arr, 6);
    indDeletion(arr, size, index);
    size-=1;
    display(arr, size);
    return 0;
}








