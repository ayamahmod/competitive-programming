class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)  return -1;
        int PivotIdx=findPivot(nums, 0, nums.size()-1);
        if(PivotIdx==-1)    return binarySearch(nums, 0, nums.size()-1, target);
        else if(nums[PivotIdx]==target) return PivotIdx;
        else if(nums[0]<=target)
            return binarySearch(nums, 0, PivotIdx-1, target);
        else return binarySearch(nums, PivotIdx+1, nums.size()-1, target);
    }

    int findPivot(vector<int>& nums, int low, int high){
        if(low>high)    return -1;
        //if(low==high)     return low;

        int mid=(low+high)/2;
        if(mid<high && nums[mid]>nums[mid+1])   return mid;
        if(mid>low && nums[mid]<nums[mid-1])    return mid-1;
        if(nums[low]> nums[mid])
            return findPivot(nums, low, mid-1);
        return findPivot(nums, mid+1, high);
    }

    int binarySearch(vector<int>& nums, int low, int high, int target){
        if(high<low)    return -1;
        int mid=(low+high)/2;
        if(nums[mid]==target)   return mid;
        else if(nums[mid]>target)   return binarySearch(nums, low, mid-1,target);
        else return binarySearch(nums, mid+1, high, target);
    }
};
