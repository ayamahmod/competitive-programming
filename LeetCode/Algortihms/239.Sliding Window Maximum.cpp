/*
Given an array nums, there is a sliding window of size k which is moving from
the very left of the array to the very right. You can only see the k numbers in the window.
Each time the sliding window moves right by one position. Return the max sliding window.
*/
// O(NlogN)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maxs;
        if(nums.size() == 0) return maxs;
        multiset<int> window(nums.begin(), nums.begin()+k);
        for(int i = k; i <= nums.size(); ++i) {
            maxs.push_back(*window.rbegin());
            window.insert(nums[i]);
            window.erase(window.lower_bound(nums[i-k]));
        }
        return maxs;
    }
};


//O(N)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maxs;
        deque<int> dq;
        for(int i = 0; i < nums.size(); ++i) {
            while(!dq.empty() && dq.front() <= i-k)
                dq.pop_front();
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
            if(i >= k-1)
                maxs.push_back(nums[dq.front()]);
        }
        return maxs;
    }
};
