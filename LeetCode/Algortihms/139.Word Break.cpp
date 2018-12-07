/*
Given a non-empty string s and a dictionary wordDict containing
a list of non-empty words, determine if s can be segmented into
a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
*/
//O(n^2)
class Solution {
private:
    unordered_set<string> dict;
    bool wordBreak(string s, int start, vector<int>& memo) {
        string str = s.substr(start);
        if(dict.find(str) != dict.end())    return true;
        if(memo[start] != -1)   return memo[start];
        string ls = "";
        for(int i = start; i < s.size()-1; ++i) {
            ls+= s[i];
            if(dict.find(ls) != dict.end() && wordBreak(s, i+1, memo)) {
                memo[start] = 1;
                return true;
            }
        }
        memo[start] = 0;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i = 0; i < wordDict.size(); ++i)    dict.insert(wordDict[i]);
        vector<int> memo(s.size(), -1);
        return wordBreak(s, 0, memo);
    }
};
