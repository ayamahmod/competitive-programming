class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size();i++){
            if(i && nums[i]==nums[i-1])
              continue;
            int j=i+1, k=nums.size()-1;
            while(j<k){
                int temp=nums[i]+nums[j]+nums[k];
                if(abs(temp-target)<abs(sum-target)){
                  sum=temp;
                }

                if(temp==target)  return target;
                else if(temp<target) j++;
                else if(temp>target) k--;
            }
        }
        return sum;
    }
};
