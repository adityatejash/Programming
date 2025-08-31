#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Q6. Write a program to delete a node from a linked list at a specified position.

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

void display(struct node** head){
    struct node* temp = *head;
    while (temp != NULL){
        if (temp->link == NULL){
            printf("%d\n",temp->data);
        } else {
            printf("%d --> ",temp->data);
        }
        temp = temp->link;
    }
    return;
}

int countNodesIterative (struct node** head){
    int count = 0;
    struct node* temp = *head;
    while (temp != NULL){
        count++;
        temp = temp->link;
    }
    return count;
}

void deleteNodeAnywhere (struct node** head, int index){
    struct node* temp = *head;
    if (index < 1 ){
        printf("Node Index Starts from 1. No changes made.\n");
        return ;
    } else if (index > countNodesIterative(&temp)) {
        printf("Node doesn't exist. No changes made.\n");
        return;
    } if (*head == NULL){
        return;
    } if (index == 1){
        struct node* temp = *head;
        *head = (*head)->link;
        free(temp);
        return; 
    }
    for (int i=1; i<index-1; i++){
        temp = temp->link;
    }
    struct node* temp2 = temp->link->link;
    free(temp->link);
    temp->link = temp2;
    return; 
}

int main(){
    struct node* first = createNode(5);
    struct node* second = createNode(10);
    struct node* third = createNode(15);
    struct node* fourth = createNode(20);
    first->link = second;
    second->link = third;
    third->link = fourth;
    fourth->link = NULL;

    display(&first);
    deleteNodeAnywhere(&first,2);
    display(&first);
    return 0;
}