class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > v;
        if(candidates.size()==0)    return v;
        vector<int> curr;
        FindCombin(candidates, target, 0, curr, v);

        return v;
    }

    void FindCombin(vector<int>& candidates, int target, int idx, vector<int>& curr, vector<vector<int> >& result){
        if(target<0)
            return;

        else if(target==0)
        {result.push_back(curr);     return;}

        else{
            for(int i=idx;i<candidates.size();i++){
                curr.push_back(candidates[i]);
                FindCombin(candidates, target-candidates[i], i, curr, result);
                curr.pop_back();
            }
        }
    }
};
