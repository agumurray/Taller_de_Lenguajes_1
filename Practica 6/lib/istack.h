#ifndef ISTACK_H
#define ISTACK_H

#include <stdlib.h>

typedef struct {
    int* data;
    int top;
    int capacity;
} Stack;

Stack* s_create() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = NULL;
    stack->top = -1;
    stack->capacity = 0;
    return stack;
}

int s_push(Stack* s, int n) {
    if (s->top == s->capacity - 1) {
        // Expand the stack if it is full
        int newCapacity = s->capacity == 0 ? 1 : s->capacity * 2;
        int* newData = (int*)realloc(s->data, newCapacity * sizeof(int));
        if (newData == NULL) {
            // Error allocating memory
            return -1;
        }
        s->data = newData;
        s->capacity = newCapacity;
    }
    s->data[++s->top] = n;
    return n;
}

int s_pop(Stack* s) {
    if (s->top == -1) {
        // Stack is empty
        return -1;
    }
    return s->data[s->top--];
}

int s_top(Stack s) {
    if (s.top == -1) {
        // Stack is empty
        return -1;
    }
    return s.data[s.top];
}

int s_empty(Stack s) {
    return s.top == -1 ? 1 : 0;
}

int s_length(Stack s) {
    return s.top + 1;
}

#endif
