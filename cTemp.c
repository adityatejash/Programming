#include <stdio.h>
#include <stdlib.h>

# define max 5

struct queue {
    int item[max];
    int front, rear; 
};

void initializeQueue (struct queue* q){
    q->front = -1;
    q->rear = -1;
}

int isFull (struct queue* q){
    return q->rear == max-1;
}

int isEmpty (struct queue* q){
    return q->front == -1;
}

void enqueue (struct queue* q,int value){
    if (isFull(q)){
        printf("Queue FULL\n");
        return;
    }
    if (q->front == -1){
        q->front = 0;
    }
    q->item[++q->rear] = value;
}

void dequeue (struct queue* q){
    if (isEmpty(q)){
        printf("Queue EMPTY\n");
        return;
    }
    q->front++;
}

void display(struct queue* q){
    if (isEmpty(q)){
        printf("Queue EMPTY\n");
        return;
    }
    for (int i=q->front; i<=q->rear; i++){
        printf("%d ",q->item[i]);
    }
    printf("\n");
}

int main(){
    struct queue q;
    initializeQueue(&q);

    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,40);
    enqueue(&q,40);

    display(&q);
    
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
}