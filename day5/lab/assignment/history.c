#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 100
typedef struct Stack {
    char history[10][MAX_URL_LENGTH];
    int top;
} Stack;
void initStack(Stack *stack) {
    stack->top = -1;
}
void push(Stack *stack, const char *url) {
    if (stack->top < 9) {
        stack->top++;
        strcpy(stack->history[stack->top], url);
    }
}

int pop(Stack *stack, char *url) {
    if (stack->top == -1) {
        return 0;
    }
    strcpy(url, stack->history[stack->top]);
    stack->top--;
    return 1;
}


void displayCurrentPage(const char *currentPage) {
    printf("Current Page: %s\n", currentPage);
}
int main() {
    Stack backwardStack, forwardStack;
    char currentPage[MAX_URL_LENGTH];
    char temp[MAX_URL_LENGTH];

    initStack(&backwardStack);
    initStack(&forwardStack);
    strcpy(currentPage, "google.com");
    push(&backwardStack, currentPage);
    printf("Visited: %s\n", currentPage);

    strcpy(currentPage, "github.com");
    push(&backwardStack, currentPage);
    printf("Visited: %s\n", currentPage);

    strcpy(currentPage, "stackoverflow.com");
    push(&backwardStack, currentPage);
    printf("Visited: %s\n", currentPage);
    if (pop(&backwardStack, temp)) {
        push(&forwardStack, currentPage);
        strcpy(currentPage, temp);
        printf("\nAction: Go Back\n");
        displayCurrentPage(currentPage);
    } else {
        printf("\nNo page to go back to.\n");
    }
    if (pop(&forwardStack, temp)) {
        push(&backwardStack, currentPage);
        strcpy(currentPage, temp);
        printf("\nAction: Go Forward\n");
        displayCurrentPage(currentPage);
    } else {
        printf("\nNo page to go forward to.\n");
    }

    return 0;
}
