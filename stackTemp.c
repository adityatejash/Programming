#include <stdio.h>

#define max 5

int stack[max];
int top=-1;

void push(int value){
    if (top == max - 1){
        printf("OVERFLOW\n");
        return;
    } 
    stack[++top] = value;
    return;
}

void pop(){
    if (top == -1){
        printf("UNDERFLOW\n");
        return;
    }
    top--;
    return;
}

void print (){
    if (top == -1){
        printf("STACK EMPTY\n");
        return;
    }
    for (int i=top; i>=0; i--){
        printf("%d\n",stack[i]);
    }
    printf("\n");
    return;
}

int main(){
    push(10);
    push(20);
    push(30);
    print();
    pop();
    print();
}