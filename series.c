#include <stdio.h>
#include <stdlib.h>

void printArray (const int Array[], int size){
    printf("[");
    for (int i=0; i<size; i++){
        printf("%d",Array[i]);
        if (i < size-1) {
            printf(", ");
        }
    }
    printf("]\n");

}

void main(){
    int n;
    printf("Enter Size of Array: ");
    scanf("%d",&n);
    int A[n];

    for (int i=0; i<n; i++){
        A[i] = rand()%10;
    }

    printf("Array: ");
    printArray(A,n);

    int max, secondMax;
    if (A[0] > A[1]){
        max = A[0];
        secondMax = A[1];
    } else {
        max = A[1];
        secondMax = A[0];
    }
    for (int i=2; i<n; i++){
        if (A[i] > max){
            secondMax = max;
            max = A[i];
        } else if (A[i] <= max && A[i] > secondMax){
            secondMax = A[i];
        }
    }

    printf("Largest Number: %d\n",max);
    printf("Second Largest Number: %d\n",secondMax);
}