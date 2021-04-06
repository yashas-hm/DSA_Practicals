#include<stdio.h>

void selectionSort(int arr[], int n);

int main(){
    int list[] = {34,24,57,6,3,2,9};

    selectionSort(list, sizeof(list)/sizeof(list[0]));

    for(int i =0;i<(sizeof(list)/sizeof(list[0]));i++)
        printf("%d ", list[i]);
    return 0;
}

void selectionSort(int arr[], int n) {
    int min;
    for (int i = 0; i < n-1; i++){
        min = i;
        for (int j = i+1; j < n; j++)
          if (arr[j] < arr[min])
            min = j;

        int temp = arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}
