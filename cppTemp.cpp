#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* linkForward;
    node* linkBackward;

    node (int value){
        data = value;
        linkForward = nullptr;
        linkBackward = nullptr;
    }
};

class linkedList {
    node* head;    
public:
    linkedList (){
        head = nullptr;
    }

    // node insertion at end
    void insertAtEnd (int value){
        node* newNode = new node(value);
        
        if (head == nullptr){
            head = newNode;
            return;
        }

        node* temp = head;
        while (temp->linkForward != nullptr){
            temp = temp->linkForward;
        }
        temp->linkForward = newNode;
        newNode->linkBackward = temp;
        return;
    }

    // node deletion at end
    void deleteAtEnd (){
        if (head == nullptr){
            cout << "No elements to delete." << endl;
            return;
        } else if (head->linkForward == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        node *temp = head;
        node *previous = nullptr;
        while (temp->linkForward != nullptr){
            previous = temp;
            temp = temp->linkForward;
        }
        delete temp;
        previous->linkForward = nullptr;
        return;
    } 

    // display list
    void display(){
        node* temp = head;
        while (temp != nullptr){
            if (temp->linkForward == nullptr){
                cout << temp->data << endl;
                return;
            }
            cout << temp->data << " --> ";
            temp = temp->linkForward;
        }
        return;
    }

};

int main(){
    linkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.display();
    list.deleteAtEnd();
    list.insertAtEnd(40);
    list.display();
}