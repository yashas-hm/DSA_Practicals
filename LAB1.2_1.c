#include<stdio.h>

void bubbleSort(int arr[], int n);

int main(){
    int list[] = {34,24,57,6,3,2,9};

    bubbleSort(list, sizeof(list)/sizeof(list[0]));

    for(int i =0;i<(sizeof(list)/sizeof(list[0]));i++)
        printf("%d ", list[i]);
    return 0;
}

void bubbleSort(int arr[], int n){
   for (int i = 0; i < n-1; i++)
       for (int j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1]){
               int temp = arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;
           }
}
