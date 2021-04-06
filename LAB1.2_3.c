#include<stdio.h>

int partition (int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main(){
    int list[] = {34,24,57,6,3,2,9};
    int n = sizeof(list)/sizeof(list[0]);

    quickSort(list, 0 , n-1);

    for(int i =0;i<n;i++)
        printf("%d ", list[i]);
    return 0;
}

int partition (int arr[], int low, int high) {
    int temp, pivot = arr[high] ,i = (low - 1);
    for (int j = low; j <= high- 1; j++){
        if (arr[j] < pivot){
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1]=arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high){
        int part = partition(arr, low, high);
        quickSort(arr, low, part - 1);
        quickSort(arr, part + 1, high);
    }
} 
