// #include <stdio.h>

// int arraytraversal(int arr[], int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ", arr[i]);
//     }
// }

// // Insertiion
// int arrayinsertion(int arr[], int size, int index, int value)
// {
//     for (int i = size - 1; i >= index; i--)
//     {
//         arr[i + 1] = arr[i];
//     }
//     arr[index] = value;
// }

// // Deletion
// void indDeletion(int arr[], int size, int index)
// {
//     // if (index>=capacity)
//     // {
//     //     return -1;
//     // }
//     for (int i = index; i < size - 1; i++)
//     {
//         arr[i] = arr[i + 1];
//     }
// }

// int bubblesortArray(int arr[], int size)
// {
//     int temp;
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] > arr[i + 1])
//         {
//             temp = arr[i];
//             arr[i] = arr[i + 1];
//             arr[i + 1] = temp;
//         }
//     }
// }

// int main()
// {
//     int arr[10] = {1, 23, 4, 5, 7};
//     // int size = sizeof(arr)/sizeof(int);
//     int size = 5;
//     // arrayinsertion(arr,size,2,22);
//     // indDeletion(arr,size,2);
//     // size--;
//     bubblesortArray(arr, size);
//     arraytraversal(arr, size);

//     return 0;
// }





// #include <stdio.h>
// int main()
// {
//     int element=9,index=2;
//     int arr[10] = {1,4,2,6,8};
//     // printf("%d",sizeof(arr));
//     for (int i = 4; i >= index; i--)
//     {
//         arr[i+1] = arr[i];
//     }
//     arr[index] = element;
//     for (int i = 0; i <= 5; i++)
//     {
//         printf("%d ",arr[i]);
//     }
    
//     return 0;
// }