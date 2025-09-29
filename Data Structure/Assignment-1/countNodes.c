#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Q4. Write a program to Counting the nodes in a linked list using recursion as well as iterative approach.

struct node {
    int data;
    struct node* link;
};

struct node* createNode (int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->link = NULL;
    return newNode;
};

int countNodesIterative (struct node** head){
    int count = 0;
    struct node* temp = *head;
    while (temp != NULL){
        count++;
        temp = temp->link;
    }
    return count;
}

int countNodesRecursive(struct node** head) {
    if (*head == NULL)
        return 0;
    return 1 + countNodesRecursive(&((*head)->link));
}

void main(){
    struct node* first = createNode(5);
    struct node* second = createNode(5);
    struct node* third = createNode(5);
    first->link = second;
    second->link = third;

    printf("Iterrative: Number of nodes are %d\n",countNodesIterative(&first));
    printf("Recursive: Number of nodes are %d\n",countNodesRecursive(&first));
    return;
}