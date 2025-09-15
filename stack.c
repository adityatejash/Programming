#include <stdio.h>
#include <stdbool.h>

#define max 5

struct stack {
    int items[max];
    int top;
};

void initialize (struct stack* s){
    s->top = -1;
    return;
}

bool isFull (struct stack* s){
    if (s->top == max-1){
        return true;
    }
    return false;
}

bool isEmpty (struct stack* s){
    if (s->top == -1){
        return true;
    }
    return false;
}

void push (struct stack* s, int value){
    if (isFull(s)){
        printf("Stack OVERFLOW\n");
        return;
    } 
    s->top++ ;
    s->items[s->top] = value;
    return;
}

void pop (struct stack* s){
    if (isEmpty(s)){
        printf("Stack UBDERFLOW\n");
        return;
    }
    s->top--;
    return;
}

void peek (struct stack* s){
    if (isEmpty(s)){
        printf("Stack EMPTY\n");
        return;
    }
    for (int i=s->top; i>-1; i--){
        printf("%d\n",s->items[i]);
    }
    printf("\n");
    return;
}

int main(){
    struct stack s;
    initialize(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    peek(&s);
    pop(&s);
    push(&s, 40);
    peek(&s);
}

