#include <stdio.h>
#include <stdlib.h>

// Q2. Write a program to create a self-referential structure and link it with another structure

struct node {
    int data;
    struct node* link;
};

struct node* createNode (int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->link = NULL;
    return newNode;
};

void main(){
    struct node* first = (struct node*)malloc(sizeof(struct node));
    first->data = 10;
    first->link = NULL;

    struct node* second = (struct node*)malloc(sizeof(struct node));
    second->data = 20;
    second->link = NULL;

    first->link = second;

    printf("%d, %p --> %d, %p\n",first->data,first->link,second->data);

    return;
}