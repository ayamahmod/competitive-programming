/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

class Solution {
    unordered_map<int, unordered_set<int> > adj_list_; // node, its neighbours
    void dfs(int elem, unordered_set<int>& visited, int& len) {
        if(visited.find(elem) != visited.end()) return;
        visited.insert(elem);
        len += 1;
        for(auto it = adj_list_[elem].begin(); it != adj_list_[elem].end(); ++it)
            dfs(*it, visited, len);
    }
public:
    int longestConsecutive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) {
            int prev = nums[i] - 1, next = nums[i] + 1;
            unordered_set<int> s = adj_list_[nums[i]];
            auto it1 = adj_list_.find(prev);
            if(it1 != adj_list_.end()) {
                it1->second.insert(nums[i]);
                s.insert(prev);
            }
            auto it2 = adj_list_.find(next);
            if(it2 != adj_list_.end()) {
                it2->second.insert(nums[i]);
                s.insert(next);
            }
            adj_list_[nums[i]] = s;
        }
        unordered_set<int> visited;
        int longest = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(visited.find(nums[i]) == visited.end()) {
                int len = 0;
                dfs(nums[i], visited, len);
                longest = max(len, longest);
            }
        }
        return longest;
    }
};
