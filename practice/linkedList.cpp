// Linked List

#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* link;
};

node* createNode (int value){
    node* newNode = new node();
    newNode->data = value;
    newNode->link = nullptr;
    return newNode;
}

node* insertAtEnd (node* head, int value){
    node* newNode = createNode(value);

    if (head == nullptr){
        return newNode;
    }

    node* temp = head;
    while (temp->link != nullptr){
        temp = temp->link;
    }

    temp->link = newNode;
    
    return head;
}

node* insertAtBeginning (node* head, int value){
    node* newNode = createNode(value);

    newNode->link = head;
    head = newNode;

    return head;
}

void print (node* head){
    node* temp = head;
    while (temp != nullptr){
        cout << temp->data << " -> " ;
        temp = temp->link;
    }
    return;
}

int main(){
    node* list = nullptr;
    int a[] = {10,20,30};
    int size = sizeof(a)/sizeof(a[0]);

    for (int i=0; i<size; i++){
        list = insertAtEnd(list, a[i]);
    }

    print(list);
}