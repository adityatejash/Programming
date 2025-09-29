#include <stdio.h>

# define max 5

int stack[max];
int top = -1;

void push (int value){
    if (top == max-1){
        printf("Stack FULL\n");
        return;
    }
    stack[++top] = value;
    return;
}

int pop(){
    if (top == -1){
        printf("Stack EMPTY\n");
        return -1;
    }
    return stack[top--];
}

void enqueue (int value){
    push(value);
    printf("%d Enqueued\n", value);
    return;
}

int dequeue() {
    if (top == -1) {
        printf("Queue is empty\n");
        return -1;
    }

    int x = pop();
    if (top == -1) {
        return x;
    } else {
        int res = dequeue(); 
        push(x);             
        return res;
    }
}

void display(){
    printf("Queue: ");
    for (int i=top; i>-1; i--){
        printf("%d ",stack[i]);
    }
    printf("\n");
    return;
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
}