/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.*/

/*

THIS IS FOR IF YOU HAVE TO TAKE MINIMUM 1 ELEMENT
IF NOT SET THE CURMAX TO 0

*/

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int curmax  = nums[0] , maxn = nums[0];
		for (int i = 1; i < nums.size(); i++) {

			// either you take by addition or the number only
			curmax = max(curmax + nums[i], nums[i]);
			maxn = max(curmax, maxn);
		}
		return maxn;
	}
};

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		int cursum[n];
		cursum[0] = nums[0];
		for (int i = 1; i < n; i++) {
			cursum[i] = max(cursum[i - 1] + nums[i], nums[i]);
		}
		return *max_element(cursum, cursum + n);
	}
};



class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		int cursum[n];
		cursum[0] = nums[0];
		for (int i = 1; i < n; i++) {
			if (cursum[i - 1] + nums[i] < nums[i])
				cursum[i] = nums[i];
			else
				cursum[i] = nums[i] + cursum[i - 1];
		}
		return *max_element(cursum, cursum + n);
	}
};