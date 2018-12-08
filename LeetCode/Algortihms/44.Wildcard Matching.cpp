/*
Given an input string (s) and a pattern (p),
implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int> > memo(s.size()+1, vector<int>(p.size()+1, -1));
        return match(s, 0, p, 0, memo);
    }

    bool matchChar(char c, char p) {
        return p == '?' || p == '*' || c == p;
    }

    bool match(string& s, int s1, string& p, int s2, vector<vector<int> >& memo) {
        if(memo[s1][s2] != -1) return memo[s1][s2];
        if(s2 >= p.size()) {
            memo[s1][s2] = s1 >= s.size();
        } else if(s1 >= s.size()) {
            for(int i = s2; i < p.size(); i++) {
                if(p[i] != '*') { memo[s1][s2] = false; break; }
            }
            if(memo[s1][s2] == -1)  memo[s1][s2] = true;
        } else if(p[s2] == '*') { // wildcard matching
            bool cond = match(s, s1, p, s2+1, memo);
            for(int i = s1; i < s.size() && matchChar(s[i], p[s2]) && !cond; ++i) {
                cond |= match(s, i+1, p, s2+1, memo);
            }
            memo[s1][s2] = cond;
        } else {
            if(matchChar(s[s1], p[s2]))
                return match(s, s1+1, p, s2+1, memo);
            memo[s1][s2] = false;
        }
        return memo[s1][s2];
    }
};
