#include <stdio.h>

# define max 5

int stack1[max], stack2[max];
int top1 = -1, top2 = -1;

void push(int stack[], int *top, int value){
    if (*top == max-1){
        printf("Stack FULL\n");
        return;
    }
    stack[++(*top)] = value;
}

int pop(int stack[], int *top){
    if (*top == -1){
        printf("Stack EMPTY\n");
        return -1;
    }
    return stack[(*top)--];
}

void enqueue(int value){
    push(stack1,&top1, value);
    printf("%d enqueued\n", value);
}

int dequeue(){
    if (top2 == -1){
        while (top1 != -1){
            int popped = pop(stack1, &top1);
            push(stack2, &top2, popped);
        }
    }
    int dequeued = pop(stack2, &top2);
    printf("%d dequeued\n", dequeued);
    return dequeued;
}

void display() {
    printf("Queue: ");
    for (int i = top2; i >= 0; i--) {
        printf("%d ", stack2[i]);
    }
    for (int i = 0; i <= top1; i++) {
        printf("%d ", stack1[i]);
    }
    printf("\n");
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
}