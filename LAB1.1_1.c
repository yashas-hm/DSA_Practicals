#include<stdio.h>

int linearSearch(int list[], int searchElement, int length);

int main(){
    int list[] = {34,24,57,6,3,2,9}, searchElement, size, position;
    size = sizeof(list)/sizeof(list[0]);
    printf("Enter element to search : ");
    scanf("%d", &searchElement);

    position = linearSearch(list, searchElement, size);

    if(position==-1){
        printf("\nElement not found in array\n");
    }else{
        printf("Element found at position %d", position);
    }
    return 0;
}

int linearSearch(int list[], int searchElement, int length){
    for(int i=0;i<length;i++){
        if(list[i]==searchElement){
            return i;
        }
    }
    return -1;
}
