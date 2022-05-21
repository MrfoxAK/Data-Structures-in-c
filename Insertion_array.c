// #include <stdio.h>


// //Traversal
// void display(int arr[], int n){
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d\n",arr[i]);
//     }
    
// }


// // Insertion
// int indInsertion(int arr[], int size, int element , int capacity, int index ){
//     if (size>=capacity)
//     {
//         return -1;
//     }
//     for (int i = size-1; i>=index; i--)
//     {
//         arr[i+1] = arr[i];
//     }
//     arr[index] = element;
//     return 1;
// }


// int main()
// {
//     int size=6, element = 45, index = 1;
//     int arr[100] = {1,2,3,4,5,6};
//     // display(arr, 6);
//     indInsertion(arr, size,  element , 100, index);
//     size+=1;
//     display(arr, 6);
//     return 0;
// }

//same
#include <stdio.h>
//Traversal
void display(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
}

void indInsertion(int arr[], int size, int capacity,int element, int index){
    if(size>=capacity){
        return -1;
    }
    for (int i = size-1; i >= index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int main()
{
    int element = 245,index=1,size=8;
    int arr[100] = {1,2,3,4,5,45,6,65};
    indInsertion(arr, size, 100, element, index);
    size+=1;
    display(arr, size);
    return 0;
}





















