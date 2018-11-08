// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
// Example 1:
//
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true
// Example 2:
//
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// Output: false

class Solution {
public:
bool isInterleave(string s1, string s2, string s3) {
  int l = s3.size();
  int m = s1.size();
  int n = s2.size();
  if(l != m+n) return false;
  ++l; ++m; ++n;
  vector<vector<bool> > dp(m,vector<bool>(n, false));

  for(int i = 0; i < m; ++i) {
      for(int j = 0; j < n; ++j) {
          if(i==0 && j==0) dp[i][j] = true;
          else if(i==0) dp[i][j] = dp[i][j-1] && (s3[j-1] == s2[j-1]);
          else if(j==0) dp[i][j] = dp[i-1][j] && (s3[i-1] == s1[i-1]);
          else dp[i][j] = (dp[i-1][j] && s3[i+j-1] == s1[i-1]) ||
            (dp[i][j-1] && s3[i+j-1] == s2[j-1]);
      }
  }

  return dp[m-1][n-1];
}

};
