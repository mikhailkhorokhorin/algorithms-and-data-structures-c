#include <stdbool.h>

#define POOL_SIZE 1024
#define QUEUE_EMPTY -1

typedef struct Queue {
    int buff[POOL_SIZE];
    int size;
    int head;
} Queue;

void init(Queue* queue) {
    queue->size = 0;
    queue->head = 0;
}

bool isEmpty(Queue* queue) {
    return queue->size == 0;
}

int size(Queue* queue) {
    return queue->size;
}

bool push(Queue* queue, int val) {
    if (queue->size >= POOL_SIZE)
        return false;

    queue->buff[(queue->head + queue->size) % POOL_SIZE] = val;
    queue->size++;

    return true;
}

bool pop(Queue* queue, int* out) {
    if (queue->size == 0)
        return false;

    *out = queue->buff[queue->head];
    queue->head = (queue->head + 1) % POOL_SIZE;
    queue->size--;

    return true;
}

int top(Queue* queue) {
    if (queue->size > 0)
        return queue->buff[queue->head];

    return QUEUE_EMPTY;
}

void destroy(Queue* queue) {
    queue->size = 0;
    queue->head = 0;
}
