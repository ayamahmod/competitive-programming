class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0)  return 0;
        return binarySearch(nums, 0, nums.size()-1, target);
    }

    int binarySearch(vector<int>& nums, int low, int high, int target){
        if(high<low)    return low;//low

        int mid=(low+high)/2;

        if(nums[mid]==target)   return mid;

        else if(target < nums[mid])
            return binarySearch(nums, low, mid-1, target);

        else
            return binarySearch(nums, mid+1, high, target);
    }
};
