struct node* reverse (struct node* head){
    if (head == NULL || head->link == NULL){
        return head;
    }
    struct node* newHead =  reverse(head->link);
    head->link->link = head;
    head->link = NULL;
    return newHead;;
}