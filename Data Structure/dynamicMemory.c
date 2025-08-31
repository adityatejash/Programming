#include <stdio.h>
#include <stdlib.h>

// Q1. Write a program to illustrate Dynamic memory allocation (malloc, calloc, realloc and free)

void funcMalloc (){
    // malloc prints garbage value when not initialized
    printf("Before initialization\n");
    int* arr = (int*)malloc(5*sizeof(int));
    for (int i=0; i<5; i++){
        printf("%d ", arr[i]); 
    }
    printf("\nAfter initialization\n");
    for (int i=0; i<5; i++){
        arr[i] = i*10;
        printf("%d ", arr[i]); 
    }    
    printf("\nMemory Freed\n");
    free(arr);
}

void funcCalloc(){
    // calloc prints zero when not initialized
    printf("Before initialization\n");
    int* arr = (int*)calloc(5,sizeof(int));
    for (int i=0; i<5; i++){
        printf("%d ", arr[i]); 
    }
    printf("\nAfter initialization\n");
    for (int i=0; i<5; i++){
        arr[i] = i*10;
        printf("%d ", arr[i]); 
    }    
    printf("\nMemory Freed\n");
    free(arr);
}

void funcRealloc(){
    int* arr = (int*)malloc(5*sizeof(int));
    printf("Before Reallocation\n");
    for (int i=0; i<5; i++){
        arr[i] = i*10;
        printf("%d ", arr[i]); 
    }
    printf("\nAfter Reallocation\n");
    arr = (int*)realloc(arr,3*sizeof(int));
    for (int i=0; i<3; i++){
        printf("%d ", arr[i]); 
    }    
    printf("\nMemory Freed\n");
    free(arr);
}

int main (){
    printf("----Malloc----\n");
    funcMalloc();
    printf("----Calloc----\n");
    funcCalloc();
    printf("----Realloc----\n");
    funcRealloc();
}