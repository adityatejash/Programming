#include <stdio.h>

int main(){
    int arr[] = {1,2,3,4};
    int s = sizeof(arr)/sizeof(arr[0]);

    int i = 0;
    int j = s-1;

    while (i<j){
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;

        i++;
        j--;
    }
    
    for (int i=0; i<s; i++){
        printf("%d ",arr[i]);
    }
}