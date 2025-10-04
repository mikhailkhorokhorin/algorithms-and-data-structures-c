int binary_search_iterative(int arr[], int n, int key) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int binary_search_recursive(int arr[], int left, int right, int key) {
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binary_search_recursive(arr, mid + 1, right, key);
    else
        return binary_search_recursive(arr, left, mid - 1, key);
}