#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Q5. Write a program to reverse a linked list using recursion.

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
}

struct node* reverse(struct node** head) {
    if (*head == NULL || (*head)->link == NULL) {
        return *head;
    }
    struct node* newHead = reverse(&((*head)->link));
    (*head)->link->link = *head;
    (*head)->link = NULL;

    return newHead;
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
    first = reverse(&first);
    display(&first);

}
