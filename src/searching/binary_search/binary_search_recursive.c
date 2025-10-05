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