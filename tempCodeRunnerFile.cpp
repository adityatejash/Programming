#include <stdio.h>
#include <stdlib.h> // Required for exit()

#define CAPACITY 5 // Defines the maximum size of the stack

// The structure for the stack
struct Stack {
    int top;             // Index of the top element
    int items[CAPACITY]; // The array to hold the stack elements
};

// Function to initialize an empty stack
void initialize(struct Stack *s) {
    s->top = -1; // -1 signifies that the stack is empty
}

// Check if the stack is full
int isFull(struct Stack *s) {
    if (s->top == CAPACITY - 1) {
        return 1; // True, stack is full
    }
    return 0; // False, stack has space
}

// Check if the stack is empty
int isEmpty(struct Stack *s) {
    if (s->top == -1) {
        return 1; // True, stack is empty
    }
    return 0; // False, stack has elements
}

// Add an element to the top of the stack
void push(struct Stack *s, int element) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push element %d.\n", element);
        return;
    }
    s->top++; // Increment top index
    s->items[s->top] = element; // Place element at the new top
    printf("Pushed %d onto the stack.\n", element);
}

// Remove and return the top element
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
        exit(EXIT_FAILURE); // Exit the program on underflow
    }
    int popped_element = s->items[s->top];
    s->top--; // Decrement top index
    return popped_element;
}

// Return the top element without removing it
int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot peek.\n");
        exit(EXIT_FAILURE);
    }
    return s->items[s->top];
}

// Main function to demonstrate stack operations
int main() {
    struct Stack myStack;
    initialize(&myStack);

    // Push elements onto the stack
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    // See the top element
    printf("Top element is: %d\n", peek(&myStack));

    // Pop an element
    printf("Popped %d from the stack.\n", pop(&myStack));
    printf("Top element is now: %d\n", peek(&myStack));

    // Push more elements to test overflow
    push(&myStack, 40);
    push(&myStack, 50);
    push(&myStack, 60); // This will cause an overflow

    // Pop all remaining elements
    printf("Popped %d from the stack.\n", pop(&myStack));
    printf("Popped %d from the stack.\n", pop(&myStack));
    printf("Popped %d from the stack.\n", pop(&myStack));
    // The next pop would cause an underflow
    // pop(&myStack);

    return 0;
}
