int findPivot(vector<int>& arr, int low, int high) {

    int N = arr.size();
    while (low <= high) {
        if (arr[low] <= arr[high]) {
            return low;
        }
        int mid = (low + high) / 2;
        int prev = (mid + N - 1) % N;
        int next = (mid + 1) % N;
        if (arr[mid] <= arr[prev] and arr[mid] <= arr[next])
            return mid;

        if (arr[low] <= arr[mid])
            low = mid + 1;
        else if (arr[mid] <= arr[high])
            high = mid - 1;
    }
    return -1;
}


/*
THIS ALSO SOLVES PROBLEMS LIKE NO . OF ROTATIONS
AND SEARCHING IN SORTED ROTATED ARRAY
*/


/*
VERY VERY IMPORTANT!!
MODIFICATION
*/

bool search(vector<int>& a, int t) {
    int s = 0;
    int e = a.size() - 1;

    while (s <= e) {
        // reach end of duplicates from start
        while ((s + 1 <= e) && (a[s] == a[s + 1])) {
            s++;
        }

        // reach end of duplicates from end
        while ((s <= e - 1) && (a[e] == a[e - 1])) {
            e--;
        }

        int mid = s + (e - s) / 2;
        if (a[mid] == t) return true;
        if (a[s] <= a[mid]) { // left part is sorted
            if (t >= a[s] && t < a[mid]) e = mid - 1;
            else s = mid + 1;
        } else { // right part is sorted
            if (t > a[mid] && t <= a[e]) s = mid + 1;
            else e = mid - 1;
        }
    }
    return false;
}