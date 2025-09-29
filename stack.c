#include <stdio.h>

#define max 5

int stack[max];
int top = -1;

void push(int value){
    if (top == max - 1){
        printf("Stack FULL\n");
        return;
    }
    stack[++top] = value;
    printf("Pushed Item: %d\n", value);
    return;
}

void pop(){
    if (top == -1){
        printf("Stack EMPTY\n");
        return;
    }
    printf("Popped Item: %d\n",stack[top--]);
    return;
}

void display(){
    for (int i=top; i>-1; i--){
        printf("%d\n",stack[i]);
    }
    return;
}

int main(){
    for (int i=1; i<=5; i++){
        push(10*i);
    }
    display();
    pop();
    display();
}