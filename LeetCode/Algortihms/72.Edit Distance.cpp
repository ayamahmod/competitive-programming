class Solution {
public:
  bool isScramble(string s1, string s2) {
    if(s1.size() != s2.size())  return false;
    int len = s1.size();
    vector<vector<vector<bool> > > dp(len+1, vector<vector<bool> >(len, vector<bool>(len)));
    for(int i = 0; i < len; ++i)
      for(int j = 0; j < len; ++j)
        dp[1][i][j] = (s1[i] == s2[j]);

    for(int l = 2; l <= len; ++l) {
        for(int i = 0; i < len-l+1; ++i) {
            for(int j = 0; j < len-l+1; ++j) {
              dp[l][i][j] = false;
              for(int k = 1; k < l; ++k) {
                if(dp[k][i][j] && dp[l-k][i+k][j+k] ||
                  dp[k][i][j+l-k] && dp[l-k][i+k][j]) {
                    dp[l][i][j] = true;
                    break;
                }
              }
            }
        }
    }
    return dp[len][0][0];
  }
};
