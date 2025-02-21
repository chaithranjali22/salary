#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NAME_LENGTH 50
#define MAX_STOCK_SIZE 10
typedef struct Stack {
    char stock[MAX_STOCK_SIZE][MAX_ITEM_NAME_LENGTH]; 
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1; 
void addStock(Stack *stack, const char *item) {
    if (stack->top < MAX_STOCK_SIZE - 1) {
        stack->top++;
        strcpy(stack->stock[stack->top], item);
        printf("Stock Added: %s\n", item);
    } else {
        printf("Warehouse is full, cannot add more items!\n");
    }
}
int dispatchStock(Stack *stack, char *item) {
    if (stack->top == -1) {
        return 0; 
    }
    strcpy(item, stack->stock[stack->top]);
    stack->top--;
    return 1;
}
void showRemainingStock(Stack *stack) {
    if (stack->top == -1) {
        printf("No remaining stock.\n");
        return;
    }

    printf("Remaining Stock: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%s", stack->stock[i]);
        if (i != 0) {
            printf(", ");
        }
    }
    printf("\n");
}
int main() {
    Stack warehouse;
    char dispatchedItem[MAX_ITEM_NAME_LENGTH];

    initStack(&warehouse);
    addStock(&warehouse, "Item A");
    addStock(&warehouse, "Item B");
    addStock(&warehouse, "Item C");
    if (dispatchStock(&warehouse, dispatchedItem)) {
        printf("\nDispatching Item: %s\n", dispatchedItem);
    } else {
        printf("\nNo items to dispatch.\n");
    }
    showRemainingStock(&warehouse);

    return 0;
}
