#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Circular Linked-List

// Structure for Linked-List
struct node {
    int data;
    struct node* link;
};

// Creating Node
struct node* createNode (int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->link = NULL;
    return newNode; 
}

void insertAtEnd (struct node** head, int value){
    struct node* newNode = createNode(value);
    if (*head == NULL){
        *head = newNode;
        return;
    }
    struct node* temp = *head;
    while (temp->link != NULL){
        temp = temp->link;
    }
    temp->link = newNode;
}