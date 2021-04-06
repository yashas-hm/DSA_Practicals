#include<stdio.h>

int binarySearch(int list[], int low, int high, int searchElement);

int main(){
    int list[] = {1,2,3,4,5,6,7,8,9,10}, serachElement, size, position;
    size = sizeof(list)/sizeof(list[0]);

    printf("Enter element to search : ");
    scanf("%d", &searchElement);

    position = binarySearch(list, 0, size-1, searchElement);

    if(position==-1){
        printf("Element not found in array\n");
    }else{
        printf("Element found at position %d", position);
    }
    return 0;
}

int binarySearch(int list[], int low, int high, int searchElement){
    if(high>1){
        int mid = low+(high-1)/2;
        if(mid==searchElement)
            return mid;
        else if(list[mid]>searchElement)
            return binarySearch(list, low, mid-1, searchElement);
        else if(list[mid]<searchElement)
            return binarySearch(list, mid+1, high, searchElement);
    }
    return -1;
}
