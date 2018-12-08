/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list,
and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        vector<int> res(digits.size());
        for(int i = digits.size()-1; i >= 0; --i) {
            int s = digits[i] + c;
            res[i] = s%10;
            c = s/10;
        }
        if(c)
            res.insert(res.begin(), 1);
        return res;
    }
};
