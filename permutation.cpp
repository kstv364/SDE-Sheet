void permute(string s, vector<string> &ans, int l, int r) {
    if (l == r) ans.push_back(s);
    else {
        for (int i = l; i <= r; i++) {
            swap(s[l], s[i]);
            permute(s, ans,  l + 1, r);
            swap(s[l], s[i]);
        }
    }
}

void testcase() {
    string s;
    cin >> s;
    vector<string> ans;
    permute(s, ans, 0, s.length() - 1);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
}
