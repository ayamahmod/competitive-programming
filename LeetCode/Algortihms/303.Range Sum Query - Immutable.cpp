// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

class NumArray {
private:
    vector<int> dp;
public:
    NumArray(vector<int> nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(i==0) dp.push_back(nums[0]);
            else dp.push_back(dp[i-1]+nums[i]);
        }
    }

    int sumRange(int i, int j) {
        return dp[j]-dp[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
