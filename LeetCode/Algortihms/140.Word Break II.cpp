/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
add spaces in s to construct a sentence where each word is a valid dictionary word.
Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
*/
class Solution {
private:
    unordered_set<string> dict;
    bool wordBreak(string s, int start, vector<vector<int> >& memo) {
        string str = s.substr(start);
        if(memo[start].size() >= 1)   return memo[start][0] != -1;
        if(dict.find(str) != dict.end()) {
            memo[start].push_back(s.size());
        }
        string ls = "";
        for(int i = start; i < s.size()-1; ++i) {
            ls+= s[i];
            if(dict.find(ls) != dict.end() && wordBreak(s, i+1, memo)) {
                memo[start].push_back(i+1);
            }
        }
        if(memo[start].size() == 0) memo[start].push_back(-1);
        return memo[start][0] != -1;
    }

    void generateAllStrings(const string& s, string prefix, int idx, const vector<vector<int> >& memo, vector<string>& res) {
        for(int i = 0; i < memo[idx].size(); ++i) {
            int j = memo[idx][i];
            string str = prefix + s.substr(idx, j-idx);
            if(j >= s.size())  res.push_back(str);
            else {
                str += ' ';
                generateAllStrings(s, str, j, memo, res);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(int i = 0; i < wordDict.size(); ++i)    dict.insert(wordDict[i]);
        vector<vector<int> > memo(s.size());
        bool can_break = wordBreak(s, 0, memo);
        vector<string> res;
        if(!can_break) return res;
        generateAllStrings(s, "", 0, memo, res);
        return res;
    }
};
