class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans;
        int nmax = *max_element(nums.begin(), nums.begin() + k );
        int n = nums.size();
        ans.push_back(nmax);
        for (int i = k; i < n; i++) {
            if (nums[i - k] == nmax)
                nmax = *max_element(nums.begin() + i - k + 1, nums.begin() + i + 1 );
            else
                nmax = max(nmax, nums[i]);
            ans.push_back(nmax);
        }
        return ans;
    }
};