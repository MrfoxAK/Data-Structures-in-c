#include <stdio.h>


// Linear search
int Linersearch(int arr[], int size, int element){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==element)
        {
            return i;
        }
        return -1;
    }
    
}


// Binary search
int Binarysearch(int arr[], int size, int element){
    int low,mid,high;
    low = 0;
    high = size-1;
    // start searching
    // Keep searching until low<=high
    while (low<=high)
    {
        mid = (low+high)/2;
        if (arr[mid]==element)
        {
            return mid;
        }
        if (arr[mid]<element)
        {
            low = mid + 1;
        }
        else{
            high = mid - 1; 
        }
    }
    // searching ending
    return -1;
}


int main()
{
    // Unsorted array for linear search
    // int arr[] = {1,23,45,5,56,677,889,9,121};
    // int size = sizeof(arr)/sizeof(int);
    // int element = 67;
    // Sorted array for Binary search
    int arr[] = {1,23,45,55,56,67,88,91,121};
    int size = sizeof(arr)/sizeof(int);
    int element = 121;
    // int sb = Linersearch(arr,size,element);
    int sb = Binarysearch(arr,size,element);
    printf("The element %d is found at index: %d\n",element,sb);
    return 0;
}























