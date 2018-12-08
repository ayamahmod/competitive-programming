/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number
on it represented by array nums. You are asked to burst all the balloons.
If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.
Here left and right are adjacent indices of i. After the burst, the left and
right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:

You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> nums2(nums.size()+2);
        nums2[0] = 1; nums2[nums2.size()-1] = 1;
        for(int i = 0; i < nums.size(); ++i)    nums2[i+1] = nums[i];
        vector<vector<int> > dp(nums2.size(), vector<int>(nums2.size(), 0));
        for(int i = 1; i < nums2.size()-1; ++i) {
            for(int j = i; j >= 1; --j) {
                for(int k = j; k <= i; ++k) {
                    dp[j][i] = max(nums2[j-1]*nums2[k]*nums2[i+1] + dp[j][k-1] + dp[k+1][i], dp[j][i]);
                }
            }
        }
        return dp[1][nums2.size()-2];
    }
};
