class Solution {
public:
    int robI(vector<int>& nums, int s, int e) {
        vector<int> dp(nums.size());
        for(int i = s; i <= e; ++i) {
            if(i==s) dp[i] = nums[i];
            else if(i==s+1) dp[i] = max(nums[i-1], nums[i]);
            else dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[e];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        return max(robI(nums, 0, nums.size()-2), robI(nums, 1, nums.size()-1));
    }
};
