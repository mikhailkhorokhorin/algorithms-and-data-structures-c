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

void quick_sort_recursive(int arr[], int left, int right) {
    if (left < right) {
        int p = partition(arr, left, right);
        quick_sort_recursive(arr, left, p);
        quick_sort_recursive(arr, p + 1, right);
    }
}
