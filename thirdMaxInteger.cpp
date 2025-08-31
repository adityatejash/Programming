#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    srand(time(NULL));
    int n;
    printf("Enter Size of Array: ");
    scanf("%d",&n);
    int A[n];

    for (int i=0; i<n; i++){
        A[i] = rand()%10;
    }

    A[2] = 2;
    A[1] = 4;

    printf("Array: ");
    printArray(A,n);

    int max, secondMax, thirdMax;
    if (A[0] > A[1] && A[0] > A[2]){
        max = A[0];
        if (A[1] > A[2]){
            secondMax = A[1];
            thirdMax = A[2];
        } else {
            secondMax = A[2];
            thirdMax = A[1];
        }
    } else if (A[1] > A[0] && A[1] > A[2]){
        max = A[1];
        if (A[0] > A[2]){
            secondMax = A[0];
            thirdMax = A[2];
        } else {
            secondMax = A[2];
            thirdMax = A[0];
        }
    } else {
        max = A[2];
        if (A[0] > A[1]){
            secondMax = A[0];
            thirdMax = A[1];
        } else {
            secondMax = A[1];
            thirdMax = A[0];
        }
    }

    for (int i=3; i<n; i++){
        if (A[i] >= max){
            thirdMax = secondMax;
            secondMax = max;
            max = A[i];
        } else if (A[i] >= secondMax && A[i] < max){
            thirdMax = secondMax;
            secondMax = A[i];
        } else if (A[i] >= thirdMax && A[i] < secondMax){
            thirdMax = A[i];
        }
    }

    printf("Largest Number: %d\n",max);
    printf("Second Largest Number: %d\n",secondMax);
    printf("Third Largest Number: %d\n",thirdMax);
}