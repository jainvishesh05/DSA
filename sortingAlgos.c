#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

void swap(int *a, int *b)
{

    int temp = *b;
    *b = *a;
    *a = temp;
}

void bubbleSort(int *arr, int size)
{

    for (int i = size - 1; i > 0; i--)
    {
        bool flag = true;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                flag = false;
                swap(&arr[j], &arr[j + 1]);
            }
        }
        if (flag)
            return;
    }
}

void insertionSort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i;
        int temp = arr[j];
        while (j > 0 && temp > arr[j - 1])
        { // decending order
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
    }
}

void selectionSort(int *arr, int size)//not adaptive,  not stable
{//minimum number of swaps
    for (int j = 0; j < size - 1; j++)
    {
        int index = j;
        for (int i = j+ 1; i < size; i++)
        {
            if (arr[i] < arr[index])
            {
                index = i;
            }
        }
        if (index != j)
        {
            swap(&arr[j], &arr[index]);//not stable
        }
    }
}

int partition(int arr[] , int low , int high){
    int pivot = arr[high];
    int i = low-1;
    for (int j=low ;j<high;j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i] , &arr[j]);
        }
    }
    swap(&arr[i+1] , &arr[high]);
    return i+1;
}
void quickSort(int arr[] , int low , int high){
    if(low<high){
    int i = partition(arr, low ,high);
    quickSort(arr ,low, i-1);
    quickSort(arr,i+1,high);
    }
}

int main()
{
    int array[] = {2, 3, 5, 1, 3, 5, 9 , 4 , 8 , 1 , 0};
    int length = sizeof(array) / sizeof(array[0]);
    quickSort(array, 0 ,length );
    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
}