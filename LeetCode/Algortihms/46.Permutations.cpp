// Given a collection of distinct integers, return all possible permutations.
//
// Example:
//
// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

class Solution {
public:
    void permuteRecursive(vector<int>& prefix, int idx, const vector<int>& nums,
      vector<bool>& active, vector<vector<int>>& v) {
        if(idx == nums.size())
            v.push_back(prefix);
        for(int j = 0; j < nums.size(); j++) {
            if(active[j]){
                prefix.push_back(nums[j]);
                active[j] = false;
                permuteRecursive(prefix, idx+1, nums, active, v);
                prefix.pop_back();
                active[j] = true;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> active(nums.size(), true);
        vector<vector<int>> v;
        vector<int> prefix;
        permuteRecursive(prefix, 0, nums, active, v);
        return v;
    }
};
