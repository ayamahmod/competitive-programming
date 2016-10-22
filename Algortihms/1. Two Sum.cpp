class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> result(2);
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){
                int index=m[nums[i]];
                result[0]=index;
                result[1]=i;
            }
            else{
                m[target-nums[i]]=i;
            }
        }
        return result;
    }
};
