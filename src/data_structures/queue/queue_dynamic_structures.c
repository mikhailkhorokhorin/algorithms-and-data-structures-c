#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
    int size;
} Queue;

void init(Queue* queue) {
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
}

bool isEmpty(Queue* queue) {
    return queue->size == 0;
}

int size(Queue* queue) {
    return queue->size;
}

bool push(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (!newNode)
        return false;

    newNode->data = data;
    newNode->next = NULL;

    if (queue->tail)
        queue->tail->next = newNode;
    else
        queue->head = newNode;

    queue->tail = newNode;
    queue->size++;

    return true;
}

bool pop(Queue* queue, int* out) {
    if (queue->size == 0)
        return false;

    Node* removedNode = queue->head;
    *out = removedNode->data;

    queue->head = removedNode->next;

    if (queue->head == NULL)
        queue->tail = NULL;

    free(removedNode);
    queue->size--;

    return true;
}

int top(Queue* queue) {
    if (queue->size > 0)
        return queue->head->data;

    return NULL;
}

void destroy(Queue* queue) {
    Node* current = queue->head;

    while (current) {
        Node* next = current->next;
        free(current);
        current = next;
    }

    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
}
