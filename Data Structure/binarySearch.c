#include <stdio.h>

int searchRecursion (int arr[], int value, int l, int r){
    if (l > r){
        return 0;
    }
    int mid = (l+r)/2;
    if (value == arr[mid]){
        return 1;
    } else if (value < arr[mid]){
        return searchRecursion(arr, value, l, mid-1);
    } else if (value > arr[mid]){
        return searchRecursion(arr, value, mid+1, r);
    }
}

int searchIterative (int arr[], int value, int size){
    int l = 0; 
    int r = size - 1;
    
    while (l<=r){
        int mid = (l+r)/2;
        if (value == arr[mid]){
            return 1;
        } else if (value < arr[mid]){
            r = mid - 1;
        } else if (value > arr[mid]){
            l = mid + 1;
        }
    }

    return 0;
}

int main(){
    int arr[] = {5,9,17,23,25,45,59,63,71,89};
    int l = 0;
    int r = 9;

    int findValue;
    printf("Enter Value to be found: ");
    scanf("%d",&findValue);

    int foundRecursion = searchRecursion(arr, findValue, l, r);
    printf("Recursion: ");
    foundRecursion ? printf("Element Found") : printf("Element NOT found");
    printf("\n");

    int foundIterative = searchIterative(arr, findValue, 10);
    printf("Iterative: ");
    foundIterative ? printf("Element Found") : printf("Element NOT found");
    printf("\n");


    return 0;
}