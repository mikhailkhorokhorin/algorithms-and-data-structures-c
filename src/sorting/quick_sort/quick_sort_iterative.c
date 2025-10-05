#define STACK_SIZE 1024

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int left, int right) {
    int pivot = arr[(left + right) / 2];
    int i = left - 1, j = right + 1;

    while (1) {
        do
            i++;
        while (arr[i] < pivot);

        do
            j--;
        while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(&arr[i], &arr[j]);
    }
}

void quick_sort_iterative(int arr[], int n) {
    int stack[STACK_SIZE], top = -1;
    stack[++top] = 0;
    stack[++top] = n - 1;

    while (top >= 1) {
        int right = stack[top--], left = stack[top--];

        if (left < right) {
            int p = partition(arr, left, right);
            if (p + 1 < right) {
                stack[++top] = p + 1;
                stack[++top] = right;
            }
            if (left < p) {
                stack[++top] = left;
                stack[++top] = p;
            }
        }
    }
}
