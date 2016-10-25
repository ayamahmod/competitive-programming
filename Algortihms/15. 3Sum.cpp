class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > tuples;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1])
              continue;
            int j=i+1, k=nums.size()-1;
            while(j<k){
                int temp=nums[i]+nums[j]+nums[k];
                if(temp==0){
                    vector<int> tuple;
                    tuple.push_back(nums[i]);
                    tuple.push_back(nums[j++]);
                    tuple.push_back(nums[k--]);
                    tuples.push_back(tuple);

                    while(j<nums.size() && nums[j]==nums[j-1])  j++;

                    while(k>=0 && nums[k]==nums[k+1])  k--;

                }
                else if(temp<0) j++;

                else if(temp>0) k--;
            }
        }
        return tuples;
    }
};
