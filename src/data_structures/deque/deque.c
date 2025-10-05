#include <stdbool.h>
#include <stdlib.h>

#define DEQUE_EMPTY -1

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Deque {
    Node* head;
    Node* tail;
    int size;
} Deque;

void init(Deque* deque) {
    deque->head = NULL;
    deque->tail = NULL;
    deque->size = 0;
}

bool isEmpty(Deque* deque) {
    return deque->size == 0;
}

int size(Deque* deque) {
    return deque->size;
}

bool pushFront(Deque* deque, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (!newNode)
        return false;

    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = deque->head;

    if (deque->head)
        deque->head->prev = newNode;

    deque->head = newNode;

    if (!deque->tail)
        deque->tail = newNode;

    deque->size++;

    return true;
}

bool pushBack(Deque* deque, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (!newNode)
        return false;

    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = deque->tail;

    if (deque->tail)
        deque->tail->next = newNode;

    deque->tail = newNode;

    if (!deque->head)
        deque->head = newNode;

    deque->size++;

    return true;
}

bool popFront(Deque* deque, int* out) {
    if (isEmpty(deque))
        return false;

    Node* removed = deque->head;
    *out = removed->data;

    deque->head = removed->next;

    if (deque->head)
        deque->head->prev = NULL;
    else
        deque->tail = NULL;

    free(removed);
    deque->size--;

    return true;
}

bool popBack(Deque* deque, int* out) {
    if (isEmpty(deque))
        return false;

    Node* removed = deque->tail;
    *out = removed->data;

    deque->tail = removed->prev;

    if (deque->tail)
        deque->tail->next = NULL;
    else
        deque->head = NULL;

    free(removed);
    deque->size--;

    return true;
}

int front(Deque* deque) {
    if (deque->size > 0)
        return deque->head->data;

    return DEQUE_EMPTY;
}

int back(Deque* deque) {
    if (deque->size > 0)
        return deque->tail->data;

    return DEQUE_EMPTY;
}

void destroy(Deque* deque) {
    Node* current = deque->head;

    while (current) {
        Node* next = current->next;
        free(current);
        current = next;
    }

    deque->head = NULL;
    deque->tail = NULL;
    deque->size = 0;
}
