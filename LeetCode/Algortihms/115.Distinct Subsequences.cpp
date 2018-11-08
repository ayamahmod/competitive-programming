// Given a string S and a string T, count the number of distinct subsequences of S
// which equals T.
//
// A subsequence of a string is a new string which is formed from the original
// string by deleting some (can be none) of the characters without disturbing the
// relative positions of the remaining characters. (ie, "ACE" is a subsequence of
// "ABCDE" while "AEC" is not).

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m==0 && n) return 0;
        if(n==0) return 1;
        vector<vector<int> > dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i==0 && j==0) dp[i][j] = (s[i]==t[j])? 1:0;
                else if(i==0) dp[i][j] = 0;
                else if(j==0) dp[i][j] = dp[i-1][j] + ((s[i]==t[j])? 1:0);
                else {
                    dp[i][j] += (s[i]==t[j]) ? dp[i-1][j-1]:0;
                    dp[i][j] += dp[i-1][j];
                }
            }
        }
        return dp[m-1][n-1];
    }
};
