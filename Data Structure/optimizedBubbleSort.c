#include <stdio.h>

int main(){
    int arr[] = {16,15,8,7,9};
    int size = 5;

    for (int i=0; i<size-1; i++){
        int flag = 0;
        for (int j=0; j<size-1-i; j++){
            if (arr[j] > arr[j+1]){
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
            flag = 1;
        }
        if (!flag){
            break;
        }
    }

    printf("Sorted Array: ");
    for (int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
}