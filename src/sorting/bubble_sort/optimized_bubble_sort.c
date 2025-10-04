void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void optimized_bubble_sort(int arr[], int n) {
    int swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }
}