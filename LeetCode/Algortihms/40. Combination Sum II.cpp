class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
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
                if(i>idx && candidates[i]==candidates[i-1]) continue;
                curr.push_back(candidates[i]);
                FindCombin(candidates, target-candidates[i], i+1, curr, result);
                curr.pop_back();
            }
        }
    }

};
