#include <stdio.h>

#define max 5

int stack[max] = {9,2,8,5,4};
int top = max-1;

void display(){
    for (int i=top; i>-1; i--){
        printf("%d\n",stack[i]);
    }
    return;
}

void sortStack (){
    int temp[max], sortedStack[max];
    int tempTop = -1, sortedTop = -1;
    sortedStack[++sortedTop] = stack[top--];
    while (top != -1){
        if (stack[top] >= sortedStack[sortedTop]){
            sortedStack[++sortedTop] = stack[top--];
        }
        else if (stack[top] < sortedStack[sortedTop]){
            while (sortedTop != -1){
                temp[++tempTop] = sortedStack[sortedTop--];
            }
            temp[++tempTop] = stack[top--];
            while (tempTop != -1){
                sortedStack[++sortedTop] = temp[tempTop--];
            }
        }
    }
    while (sortedTop != -1){
        temp[++tempTop] = sortedStack[sortedTop--];
    }
    while (tempTop != -1){
        stack[++top] = temp[tempTop--];
    }
}

int main(){
    printf("Original Stack\n");
    display();
    sortStack();
    printf("Sorted Stack\n");
    display();
}