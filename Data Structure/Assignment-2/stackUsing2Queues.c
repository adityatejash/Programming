#include <stdio.h>
#include <stdbool.h>

#define MAX 100

struct Queue {
    int data[MAX];
    int front, rear;
};

void initQueue(struct Queue *q) {
    q->front = q->rear = -1;
}

bool isQueueEmpty(struct Queue *q) {
    return (q->front == -1);
}

bool isQueueFull(struct Queue *q) {
    return (q->rear == MAX - 1);
}

void enqueue(struct Queue *q, int value) {
    if (isQueueFull(q)) return;
    if (q->front == -1) q->front = 0;
    q->data[++q->rear] = value;
}

int dequeue(struct Queue *q) {
    if (isQueueEmpty(q)) return -1;
    int val = q->data[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return val;
}

int queueFront(struct Queue *q) {
    if (isQueueEmpty(q)) return -1;
    return q->data[q->front];
}

struct Stack {
    struct Queue q1, q2;
};

void initStack(struct Stack *s) {
    initQueue(&s->q1);
    initQueue(&s->q2);
}

void push(struct Stack *s, int value) {
    enqueue(&s->q2, value);
    while (!isQueueEmpty(&s->q1)) {
        enqueue(&s->q2, dequeue(&s->q1));
    }
    struct Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

int pop(struct Stack *s) {
    if (isQueueEmpty(&s->q1)) return -1;
    return dequeue(&s->q1);
}

int top(struct Stack *s) {
    if (isQueueEmpty(&s->q1)) return -1;
    return queueFront(&s->q1);
}

bool isStackEmpty(struct Stack *s) {
    return isQueueEmpty(&s->q1);
}

int main() {
    struct Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element: %d\n", top(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Top element: %d\n", top(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Is stack empty? %s\n", isStackEmpty(&s) ? "Yes" : "No");

    return 0;
}