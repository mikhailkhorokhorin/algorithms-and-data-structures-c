void merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int tmp[right - left + 1];

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            tmp[k++] = arr[i++];
        else
            tmp[k++] = arr[j++];
    }

    while (i <= mid)
        tmp[k++] = arr[i++];
    while (j <= right)
        tmp[k++] = arr[j++];

    for (i = 0; i < k; i++)
        arr[left + i] = tmp[i];
}

void natural_merge_sort(int arr[], int n) {
    int sorted = 0;

    while (!sorted) {
        sorted = 1;
        int left = 0;

        while (left < n - 1) {
            int mid = left;
            while (mid < n - 1 && arr[mid] <= arr[mid + 1])
                mid++;

            if (mid == n - 1)
                break;

            int right = mid + 1;
            while (right < n - 1 && arr[right] <= arr[right + 1])
                right++;

            merge(arr, left, mid, right);

            if (right < n - 1)
                sorted = 0;

            left = right + 1;
        }
    }
}
