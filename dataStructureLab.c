#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* createNode (int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->link = NULL;
    return newNode; 
}

void insertNodeAtEnd (struct node** head, int value){
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

void display (struct node* head){
    struct node* temp  = head;
    while (temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void interchange (struct node** head){
    if (*head == NULL || (*head)->link == NULL){
        return;
    } 
    struct node* temp1 = *head;
    struct node* temp2 = (*head)->link;
    while (temp2 != NULL){
        int t = temp1->data;
        temp1->data = temp2->data;
        temp2->data = t;
        
        temp1 = temp1->link;
        temp2 = temp2->link;
    }
    return;
}

int main(){
    struct node* head = NULL;
    
    insertNodeAtEnd(&head,10);
    insertNodeAtEnd(&head,20);
    insertNodeAtEnd(&head,30);
    insertNodeAtEnd(&head,40);

    printf("Before Interchange: ");
    display(head);
    
    interchange(&head);
    printf("After Interchange: ");
    display(head);

    return 0;
}

