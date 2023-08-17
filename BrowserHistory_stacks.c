#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure to represent a webpage
typedef struct {
    char url[100];
} WebPage;

// Structure to represent a stack
typedef struct {
    WebPage pages[MAX_SIZE];
    int top;
} Stack;

// Function to initialize an empty stack
void initialize(Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
bool isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push a webpage onto the stack
void push(Stack* stack, WebPage page) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->pages[++stack->top] = page;
    printf("Page '%s' added to history\n", page.url);
}

// Function to pop the top webpage from the stack
void pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Page '%s' removed from history\n", stack->pages[stack->top].url);
    stack->top--;
}

// Function to display the browsing history
void displayHistory(Stack* stack) {
    if (isEmpty(stack)) {
        printf("History is empty\n");
        return;
    }
    printf("Browsing History:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%s\n", stack->pages[i].url);
    }
}

int main() {
    Stack history;
    initialize(&history);

    // Simulating browsing history
    WebPage page1 = { "www.google.com" };
    push(&history, page1);

    WebPage page2 = { "www.openai.com" };
    push(&history, page2);

    WebPage page3 = { "www.github.com" };
    push(&history, page3);

    displayHistory(&history);

    pop(&history);
    displayHistory(&history);

    return 0;
}
