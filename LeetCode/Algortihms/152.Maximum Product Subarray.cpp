// Given an integer array nums, find the contiguous subarray within an array
// (containing at least one number) which has the largest product.
// Example 1:
//
// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:
//
// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int max_val = nums[0], min_val = nums[0], max_product = nums[0];
        for(int i = 1; i < n; ++i) {
            if(nums[i] <= 0)
                swap(max_val, min_val);
            max_val = max(max_val*nums[i], nums[i]);
            min_val = min(min_val*nums[i], nums[i]);

            max_product = max(max_val, max_product);
        }
        return max_product;
    }
};
