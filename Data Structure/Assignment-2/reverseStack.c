#include <stdio.h>

# define max 5

int stack[max] = {10,20,30,40,50};
int top = max-1;

void display(){
    for (int i=top; i>-1; i--){
        printf("%d\n",stack[i]);
    }
    return;
}

void reverseStack (){
    int temp[max];
    for (int i=0; i<max; i++){
        temp[i] = stack[i];
    }
    for (int i=0; i<=top; i++){
        stack[i] = temp[top-i];
    }
    return;
}

int main(){
    printf("Original Stack:\n");
    display();
    reverseStack();
    printf("Reversed Stack\n");
    display();
}