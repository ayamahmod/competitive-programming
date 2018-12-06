/*
A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.
*/

class Solution {
public:
    int peakElem(vector<int>& nums, int st, int end) {
        int mid = (end+st)/2;
        if(mid < nums.size()-1 && nums[mid] < nums[mid+1])
            return peakElem(nums, mid+1, end);
        if(mid > 0 && nums[mid] < nums[mid-1])
            return peakElem(nums, st, mid-1);
        return mid;
    }
    int findPeakElement(vector<int>& nums) {
        return peakElem(nums, 0, nums.size()-1);
    }
};
