#include "stack.h"
#include <stdio.h>

void StackInit(Stack* stk) {
    stk->_size = 0;
    stk->_top = -1;
}

ElementType StackTop(Stack* stk) {
    if (StackEmpty(stk)) {
        printf("Stack Empty\n");
        return 0; // Or some other appropriate error value
    }
    return stk->elements[stk->_top];
}

int StackEmpty(Stack* stk) {
    return (stk->_top == -1);
}

void StackPush(Stack* stk, ElementType element) {
    if (stk->_size >= MAX_STACK_SIZE) { // Check for stack overflow
        printf("Stack Overflow\n");
        return;
    }
    stk->_top++;
    stk->elements[stk->_top] = element;
    stk->_size++;
}

void StackPop(Stack* stk) {
    if (StackEmpty(stk)) {
        printf("Stack Empty\n");
        return;
    }
    stk->_top--;
    stk->_size--;
}
