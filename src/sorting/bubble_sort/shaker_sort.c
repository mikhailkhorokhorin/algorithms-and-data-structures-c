void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void shaker_sort(int arr[], int n) {
    int left = 0, right = n - 1;
    int swapped;

    do {
        swapped = 0;

        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                swapped = 1;
            }
        }
        right--;

        for (int i = right; i > left; i--) {
            if (arr[i - 1] > arr[i]) {
                swap(&arr[i - 1], &arr[i]);
                swapped = 1;
            }
        }
        left++;

    } while (swapped);
}