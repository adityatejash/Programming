#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Inserting Node at End
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

// Displaying Value and Address of Node
void display (struct node* head){
    struct node* temp  = head;
    while (temp != NULL){
        if (temp->link == NULL){
            printf("%d, NULL",temp->data,temp->link);            
        } else {
            printf("%d, %u --> ",temp->data,temp->link);
        }
        temp = temp->link;
    }
    printf("\n");
}

int main(){
    struct node* head = NULL;
    int value, choice;
    bool flag = true;
    while (flag){
        printf("-----------------\n");
        printf("1. Insert Node\n2. Display List\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);        
        printf("-----------------\n");

        switch (choice){
            case 1: {
                printf("Enter Value: ");
                scanf("%d",&value);
                insertNodeAtEnd(&head, value);
                break;
            }
            case 2: {
                display (head);
                break;
            }
            case 3: {
                printf("Exiting....\n");
                flag = false;
                break;
            }
            default : {
                choice = 1;
                printf("The default choice is 1.\n");
            }
        }
    }
}