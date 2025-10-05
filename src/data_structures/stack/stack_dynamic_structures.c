#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
} Node;

typedef struct Stack {
    struct Node* head;
    int size;
} Stack;

void init(Stack* stack) {
    stack->head = NULL;
    stack->size = 0;
}

bool isEmpty(Stack* stack) {
    return stack->head == 0;
}

int size(Stack* stack) {
    return stack->size;
}

bool push(Stack* stack, int data) {
    Node* newNode = malloc(sizeof(Node));

    if (!newNode)
        return false;

    newNode->data = data;
    newNode->prev = stack->head;

    stack->head = newNode;
    stack->size++;

    return true;
}

bool pop(Stack* stack, int* out) {
    if (stack->size == 0)
        return false;

    Node* removedNode = stack->head;
    *out = removedNode->data;

    stack->head = removedNode->prev;
    free(removedNode);
    stack->size--;

    return true;
}

int top(Stack* stack) {
    if (stack->head)
        return stack->head->data;
    return NULL;
}

void destroy(Stack* stack) {
    Node* current = stack->head;

    while (current) {
        Node* next = current->prev;
        free(current);
        current = next;
    }

    stack->head = NULL;
    stack->size = 0;
}
