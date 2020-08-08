int solve(int arr[], int n) {

    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 2] != arr[n - 1])
        return arr[n - 1];
    int l = 1 , r = n - 2;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] != arr[mid - 1] and arr[mid] != arr[mid + 1])
            return arr[mid];
        else if (arr[mid] == arr[mid - 1]) {
            if (mid % 2 == 1)
                l = mid + 1;
            else
                r = mid - 1;
        }
        else if (arr[mid] == arr[mid + 1]) {
            if (mid % 2 == 0)
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
}