class Solution{
public:
  void  twoSum(vector<int>& nums, int start, int k, int target, vector<int>& sol, vector<vector<int> >& Allsol){
    int i=start,j=nums.size()-1;
    while(i<j){
      int temp=nums[i]+nums[j];
      if(temp==target){
        sol.push_back(nums[i]);
        sol.push_back(nums[j]);
        Allsol.push_back(sol);
        sol.pop_back();
        sol.pop_back();
        i++;  j--;
        while(i<nums.size() && nums[i]==nums[i-1])  i++;
        while(j>=0 && nums[j]==nums[j+1]) j--;
      }
      else if(temp<target)  i++;
      else  j--;
    }
  }

  void  kSum(vector<int>& nums, int start, int k, int target, vector<int>& sol, vector<vector<int> >& Allsol){
    if(k==1){
      for(int i=start;i<nums.size();i++){
        if(nums[i]==target){
          sol.push_back(nums[i]);
          Allsol.push_back(sol);
          sol.pop_back();
          return;
        }
      }
    }
    else if(k==2){
      twoSum(nums, start, k, target, sol, Allsol);
      return;
    }
    else{
      for(int i=start;i<nums.size()-k+1;i++){
        if(i>start && nums[i]==nums[i-1]) continue;
        sol.push_back(nums[i]);
        kSum(nums, i+1, k-1, target-nums[i], sol, Allsol);
        sol.pop_back();
      }
    }
  }

  vector<vector<int>> fourSum(vector<int>& nums, int target){
    sort(nums.begin(), nums.end());
    vector<vector<int> > Allsol;
    if(nums.size()<4) return Allsol;
    vector<int> sol;
    kSum(nums, 0, 4, target, sol , Allsol);
    return Allsol;
  }
};
