class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int counter=0, j=1;
        bool isEqual=false;
        for(int i=1,j=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])  {isEqual=true;  counter++;}
            else    isEqual=false;
            if(!isEqual)
                nums[j++]=nums[i];
        }
        return nums.size()-counter;
    }
};
