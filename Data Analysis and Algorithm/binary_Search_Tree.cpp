#include <iostream>
#include <vector>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

node* createNode (int value){
    node* newNode = new node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

node* insert (node* root, int value){
    if (root == nullptr){
        return createNode(value);
    }

    if (value < root->data){
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

void inOrder (node* root){
    if (root == nullptr){
        return;
    } 

    inOrder(root->left);
    cout << root->data << ", ";
    inOrder(root->right);
}

void preOrder (node* root){
    if (root == nullptr){
        return;
    }

    cout << root->data << ", ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder (node* root){
    if (root == nullptr){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << ", ";
}

int main(){
    struct node* head = nullptr;

    vector<int> arr = {4,9,6,4,7,2,0,11,33,5,3};

    for (int i=0; i<arr.size(); i++){
        head = insert(head,arr[i]);
    }

    cout << "Inorder: ";
    inOrder(head);

    cout << endl;
    
    cout << "Preorder: ";
    preOrder(head);
    
    cout << endl;

    cout << "Postorder: ";
    postOrder(head);
}