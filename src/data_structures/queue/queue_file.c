#include <stdbool.h>
#include <stdio.h>

#define POOL_SIZE 1024
#define QUEUE_EMPTY -1

typedef struct Queue {
    FILE* buff;
    int size;
    int cap;
    int head;
} Queue;

void init(Queue* queue, const char* filename) {
    queue->buff = fopen(filename, "w+b");

    if (!queue->buff)
        return;

    queue->size = 0;
    queue->head = 0;
    queue->cap = POOL_SIZE;
}

bool isEmpty(Queue* queue) {
    return queue->size == 0;
}

int size(Queue* queue) {
    return queue->size;
}

bool push(Queue* queue, int val) {
    if (queue->size >= queue->cap)
        return false;

    fseek(queue->buff, ((queue->head + queue->size) % queue->cap) * sizeof(int), SEEK_SET);
    fwrite(&val, sizeof(int), 1, queue->buff);
    fflush(queue->buff);

    queue->size++;

    return true;
}

bool pop(Queue* queue, int* out) {
    if (queue->size == 0)
        return false;

    int val;

    fseek(queue->buff, queue->head * sizeof(int), SEEK_SET);
    fread(out, sizeof(int), 1, queue->buff);

    queue->head = (queue->head + 1) % queue->cap;
    queue->size--;

    return true;
}

int top(Queue* queue) {
    if (queue->size > 0) {
        int val;
        fseek(queue->buff, queue->head * sizeof(int), SEEK_SET);
        fread(&val, sizeof(int), 1, queue->buff);
        return val;
    }

    return QUEUE_EMPTY;
}

void destroy(Queue* queue) {
    queue->size = 0;

    if (queue->buff) {
        fclose(queue->buff);
        queue->buff = NULL;
    }
}