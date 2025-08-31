#include <stdio.h>
#include <stdlib.h>
// double linked list
struct node {
    int data;
    struct node* linkForward;
    struct node* linkBackward;
};

struct node* createNode (int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->linkBackward = NULL;
    newNode->linkForward = NULL;
    return newNode;
};

void insertAtEnd(struct node** head, int value){
    struct node* newNode = createNode(value);
    if (*head == NULL){
        *head = newNode;
        return;
    }
    struct node* temp = *head;
    while (temp->linkForward != NULL){
        temp = temp->linkForward;
    }
    temp->linkForward = newNode;
    newNode->linkBackward = temp;
    return;
}

void display(struct node** head){
    struct node* temp = *head;
    while (temp != NULL){
        if (temp->linkForward == NULL){
            printf("%d\n",temp->data);
            return;
        } else {
            printf("%d --> ",temp->data);
        }
        temp = temp->linkForward;
    }
}

void main(){
    struct node* head = NULL;
    insertAtEnd(&head,10);
    display(&head);

    insertAtEnd(&head,20);
    display(&head);

    insertAtEnd(&head,30);
    display(&head);

}