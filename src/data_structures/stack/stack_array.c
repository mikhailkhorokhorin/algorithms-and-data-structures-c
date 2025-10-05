#include <stdbool.h>

#define POOL_SIZE 1024
#define STACK_EMPTY -1

typedef struct Stack {
    int buff[POOL_SIZE];
    int size;
} Stack;

void init(Stack* stack) {
    stack->size = 0;
}

bool isEmpty(Stack* stack) {
    return stack->size == 0;
}

int size(Stack* stack) {
    return stack->size;
}

bool push(Stack* stack, int val) {
    if (stack->size >= POOL_SIZE)
        return false;

    stack->buff[stack->size] = val;
    stack->size++;

    return true;
}

bool pop(Stack* stack, int* out) {
    if (stack->size == 0)
        return false;

    stack->size--;
    *out = stack->buff[stack->size];

    return true;
}

int top(Stack* stack) {
    if (stack->size > 0)
        return stack->buff[stack->size - 1];

    return STACK_EMPTY;
}

void destroy(Stack* stack) {
    stack->size = 0;
}
