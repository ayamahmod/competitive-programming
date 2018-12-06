class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        while(i>=0 && nums[i]>=nums[i+1])   i--;
        if(i>=0){
            int j=nums.size()-1;
            while(nums[j]<=nums[i]) j--;
            swap(nums, i, j);
        }
        reverse(nums.begin()+i+1, nums.end());
    }

    void swap(vector<int>& nums, int i, int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
};

// second Solution

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
        int i = nums.size()-2;
        while(i >= 0 && nums[i+1] <= nums[i]) --i;
        if(i >= 0) {
            int j = nums.size()-1;
            while(nums[j] <= nums[i]) --j;
            int tmp = nums[j];
            nums[j] = nums[i];
            nums[i] = tmp;
        }
        reverse(nums.begin()+i+1, nums.end());
        return nums;
    }
};
