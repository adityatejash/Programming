#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode (int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
};

struct node* insert (struct node* root, int value){
    if (root == NULL){
        return createNode(value);
    }

    if (value < root->data){
        root->left = insert(root->left, value);
    } else if (value > root->data){
        root->right = insert(root->right, value);
    }
    return root;
};

void inOrder (struct node* head){
    if (head != NULL){
        inOrder(head->left);
        printf("%d, ",head->data);
        inOrder(head->right);
    }
    return;
}

void preOrder (struct node* head){
    if (head != NULL){
        printf("%d, ",head->data);
        preOrder(head->left);
        preOrder(head->right);
    }
    return;
}

void postOrder (struct node* head){
    if (head != NULL){
        postOrder(head->left);
        postOrder(head->right);
        printf("%d, ",head->data);
    }
    return;
}

int main(){
    struct node* head = NULL;

    int flag = 1;
    while (flag){
        int value;

        printf("Enter Value: ");
        scanf("%d", &value);
    
        head = insert(head,value);

        printf("Enter 0 to exit the loop otherwise 1: ");
        scanf("%d",&flag);
    }
    

    printf("Inorder: ");
    inOrder(head);
    printf("\n");

    printf("Postorder: ");
    postOrder(head);
    printf("\n");

    printf("Preorder: ");
    preOrder(head);
    printf("\n");
}