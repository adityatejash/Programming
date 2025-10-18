#include <stdio.h>
#include <stdlib.h>
#define SIZE 5  // maximum size of the queue

struct Queue {
    int items[SIZE];
    int front;
    int rear;
};

// Initialize queue
void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is full
int isFull(struct Queue *q) {
    return q->rear == SIZE - 1;
}

// Check if queue is empty
int isEmpty(struct Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

// Add an element to the queue
void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    if (q->front == -1)
        q->front = 0;  // first element
    q->items[++q->rear] = value;
    printf("%d enqueued to queue\n", value);
}

// Remove an element from the queue
void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }
    printf("%d dequeued from queue\n", q->items[q->front]);
    q->front++;
}

// Display all elements in the queue
void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->items[i]);
    printf("\n");
}

// Main function to test queue operations
int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60); // will show "Queue full"

    display(&q);

    dequeue(&q);
    dequeue(&q);

    display(&q);

    return 0;
}
