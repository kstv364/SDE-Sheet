
bool myComp(const vector<int>& a1, const vector<int>& a2) { return a1[0] < a2[0]; }
class Solution {

public:
    vector<vector<int>> merge(vector<vector<int>>& arry) {
        sort(arry.begin(), arry.end(), myComp);
        int n = arry.size();
        if (n < 2) return arry;
        vector<vector<int>> res;

        for (int i = 1; i < n; i++) {
            if (arry[i - 1][1] < arry[i][0]) {
                //no overlap, push arry[i] to res
                res.push_back(arry[i - 1]);
            } else {
                arry[i][1] = max(arry[i - 1][1], arry[i][1]);
                arry[i][0] = min(arry[i - 1][0], arry[i][0]);
            }
        }
        res.push_back(arry[n - 1]);

        return res;
    }
};