class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v(2,-1);
        if(nums.size()==0)  return v;
        binarySearch(nums, 0, nums.size()-1, target, v);
        return v;
    }

    void binarySearch(vector<int>& nums, int low, int high, int target, vector<int>& result){
        if(high<low)    return;

        if(nums[low]==nums[high] && nums[low]==target)
        {result[0]=low;     result[1]=high;  return;}

        int mid=(low+high)/2;

        if(nums[mid]==target){
            cout<<nums[mid]<<' '<<target<<endl;
            result[0]=mid;
            result[1]=mid;
            int itr1=mid,itr2=mid;
            while(itr1>low && nums[itr1]==nums[itr1-1])     result[0]=--itr1;
            while(itr2<high && nums[itr2]==nums[itr2+1])    result[1]=++itr2;
            return;
        }

        else if(target < nums[mid])
            binarySearch(nums, low, mid-1, target, result);

        else
            binarySearch(nums, mid+1, high, target, result);
    }
};
