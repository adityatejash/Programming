#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* top = NULL;

struct node* createNode (int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->link = NULL;
    return newNode;
}

void push(int value){
    struct node* newNode = createNode(value);
    if (newNode == NULL){
        return;
    }
    newNode->link = top;
    top = newNode;
    return;
}

void pop(){
    if (top == NULL){
        return;
    }
    struct node* temp = top;
    top = top->link;
    free(temp);
    return;
}

void display(){
    if (top == NULL){
        printf("Stack Empty\n");
        return;
    }
    struct node* temp = top;
    while (temp != NULL){
        printf("%d\n",temp->data);
        temp = temp->link;
    }
    printf("\n");
    return;
}

void peek(){
    
}

int main(){
    push(10);
    push(20);
    display();
    pop();
    display();

    return 0;
}