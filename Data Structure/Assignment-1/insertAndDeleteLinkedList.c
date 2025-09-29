#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Q3. Write a program to insert and delete node in linked list.

struct node{
    int data;
    struct node* link;
};

struct node* createNode (int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->link = NULL;
    return newNode;
};

void insertNodeAtEnd (struct node** head, int value) {
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
    return;
}

void insertNodeAtBeginning (struct node** head, int value){
    struct node* newNode = createNode(value);
    newNode->link = *head;
    *head = newNode;
    return;
}

void deleteNodeAtEnd (struct node** head){
    // if no node
    if (*head == NULL){
        return;
    } if ((*head)->link == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    // more than one node
    struct node* temp = *head;
    while (temp->link->link != NULL){
        temp = temp->link;
    }
    free(temp->link);
    temp->link = NULL;  
    return;  
}

void deleteNodeAtBeginning (struct node** head){
    struct node* temp = (*head)->link;
    *head = (*head)->link;
    free(temp);
    return;    
}

void display (struct node **head){
    struct node* temp = *head;
    if (temp == NULL){
        return;
    }
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

int main(){
    struct node* head = NULL;
    int value, choice, subChoice;
    bool flag = true;
    while (flag){
        printf("\n1. Insert Node\n2. Display Node\n3. Delete Node\n4. Exit\n");
        printf("Enter: ");
        scanf("%d",&choice);
        switch (choice) {
            case 1:{
                printf("Enter Value: ");
                scanf("%d",&value);
                printf("\n1. Insert at Beginning\n2. Insert at End\n");
                printf("Enter: ");
                scanf("%d",&subChoice);
                switch(subChoice){
                    case 1: {
                        insertNodeAtBeginning(&head, value);
                        break;    
                    } 
                    case 2: {
                        insertNodeAtEnd(&head, value);
                        break;
                    }
                }
                break;
            }
            case 2: {
                display(&head);
                break;
            }
            case 3: {
                printf("\n1. Delete at Beginning\n2. Delete at End\n");
                printf("Enter: ");
                scanf("%d",&subChoice);
                switch(subChoice){
                    case 1: {
                        deleteNodeAtBeginning(&head);
                        break;
                    }
                    case 2: {
                        deleteNodeAtEnd(&head);
                        break;
                    }
                }
                break;
            }
            case 4: {
                printf("Exiting....");
                flag = false;
                break;
            }
            default : {
                printf("Invalid Choice....");
                flag = false;
            }
        }
    }
}