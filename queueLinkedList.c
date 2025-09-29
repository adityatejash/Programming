#include <stdio.h>

#define max 5

struct queue {
    int item[max];
    int current;
};

void initialize (struct queue* q){
    q->current = 0;
    return;
}

void enqueue (struct queue* q, int value){
    if (q->current == max){
        printf("Queue is FULL\n");
        return;
    }
    q->item[q->current++] = value;
    return;
}

void dequeue (struct queue* q){
    if (q->current == 0){
        printf("Queue is EMPTY\n");
        return;
    }
    for (int i=0; i<q->current; i++){
        q->item[i] = q->item[i+1];
    }
    q->current--;
    return;
}

void display(struct queue* q){
    for (int i=0; i<q->current; i++){
        printf("%d, ",q->item[i]);
    }
    printf("\n");
    return;
}

int main(){
    struct queue q;
    initialize(&q);

    for (int i=1; i<=max+1; i++){
        enqueue(&q,10*i);
        display(&q);
    }
    for (int i=1; i<=max+1; i++){
        dequeue(&q);
        display(&q);
    }
}