#include <stdio.h>
#include <stdbool.h>

# define max 10

char stack[max] ;
int top = -1;

void push(char c){
    if (top == max-1){
        printf("Stack FULL\n");
        return;
    }
    stack[++top] = c;
    return;
}

void pop(){
    if (top == -1){
        printf("Stack EMPTY\n");
        return;
    }
    top--;
    return;
}

bool isMatching(char open, char close){
    if ((open == '(' && close == ')') ||
        (open == '{' && close == '}') ||
        (open == '[' && close == ']')){
            return true;
        }
    return false;
}

int main(){
    char expression[] = {"{()[{}]}"};
    bool balanced = true;
    for (int i=0; expression[i] != '\0'; i++){
        char c = expression[i];
        if (c == '[' || c == '(' || c == '{'){
            push(c);
        } else {
            if (isMatching(stack[top],c)){
                balanced = true;
                top--;
            } else {
                balanced = false;
                break;
            }
        }
    }
    balanced ? printf("Expression Balanced\n") : printf("Expression NOT Balanced\n");
                
}