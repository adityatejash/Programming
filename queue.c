#include <stdio.h>
#include <stdbool.h>

#define max 5
int queue[max];
int current = 0;

bool isFull(){
    if (current > max - 1){
        return true;
    }
    return false;
}

bool isEmpty(){
    if (current <= 0){
        return true;
    }
    return false;
}

void enqueue (int value){
    if (isFull()){
        printf("Queue is FULL\n");
        return;
    }
    queue[current++] = value;
    return;
}

void dequeue(){
    if (isEmpty()){
        printf("Queue is EMPTY\n");
        return;
    }
    for (int i=0; i<=current; i++){
        queue[i] = queue[i+1];
    }
    current--;
    return;
}

void display(){
    for (int i=0; i<current; i++){
        printf("%d, ",queue[i]);
    }
    printf("\n");
    return;
}

int main(){
    for (int i=0; i<max+1; i++){
        enqueue(10*i);
        display();
    }
    for (int i=0; i<max+1; i++){
        dequeue();
        display();
    }

    return 0;
}