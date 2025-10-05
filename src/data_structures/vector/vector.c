#include <stdbool.h>
#include <stdlib.h>

#define ELEMENT_NOT_FOUND -1

typedef struct {
    int* data;
    int size;
    int capacity;
} Vector;

void init(Vector* vector, int capacity) {
    vector->data = (int*)malloc(sizeof(int) * capacity);

    if (!vector->data)
        return;

    vector->size = 0;
    vector->capacity = capacity;
}

bool isEmpty(Vector* vector) {
    return vector->size == 0;
}

int size(Vector* vector) {
    return vector->size;
}

void resize(Vector* vector, int capacity) {
    if (capacity <= vector->capacity)
        return;

    int* data = realloc(vector->data, sizeof(int) * capacity);
    if (!data)
        return;

    vector->data = data;
    vector->capacity = capacity;
}

int get(Vector* vector, int index) {
    if (index >= 0 && index < vector->size)
        return vector->data[index];

    return ELEMENT_NOT_FOUND;
}

void set(Vector* vector, int index, int value) {
    if (index < 0 || index > vector->size)
        return;

    if (index == vector->size) {
        if (vector->size >= vector->capacity)
            resize(vector, vector->capacity * 2);

        vector->data[vector->size++] = value;
    } else {
        vector->data[index] = value;
    }
}

bool equal(Vector* l, Vector* r) {
    if (!l || !r)
        return false;

    if (l->size != r->size)
        return false;

    for (int i = 0; i < l->size; i++) {
        if (l->data[i] != r->data[i])
            return false;
    }

    return true;
}

void destroy(Vector* vector) {
    free(vector->data);

    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
}