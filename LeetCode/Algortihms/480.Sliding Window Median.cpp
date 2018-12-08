/*
Median is the middle value in an ordered integer list.
If the size of the list is even, there is no middle value.
So the median is the mean of the two middle value.

Examples:
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Given an array nums, there is a sliding window of size k which is moving from
the very left of the array to the very right. You can only see the k numbers in the window.
Each time the sliding window moves right by one position.
Your job is to output the median array for each window in the original array.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
*/

class Solution {
public:
  vector<double> medianSlidingWindow(vector<int>& nums, int k) {
      multiset<int> window(nums.begin(), nums.begin()+k);
      vector<double> res;
      multiset<int>::iterator it = next(window.begin(), k/2);
      for(int i = k; i <= nums.size(); ++i) {
          double median = *it;
          if(k%2 == 0) median = ((double)*it + *prev(it, 1))/2.0;
          res.push_back(median);
          window.insert(nums[i]);
          if (nums[i] < *it)
              it--;
          if (nums[i-k] <= *it)
              it++;
          window.erase(window.lower_bound(nums[i-k]));
      }
      return res;
  }
};
