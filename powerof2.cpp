
/*
O(1) solution

n & (n-1) == 0

special case n == 0, 1
*/

void testcase() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "NO" << endl;
        return;
    }
    if (n == 1 or (n & (n - 1)) == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

}