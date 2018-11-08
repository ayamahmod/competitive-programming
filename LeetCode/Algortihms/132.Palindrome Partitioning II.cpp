// Given a string s, partition s such that every substring of the partition is a palindrome.
//
// Return the minimum cuts needed for a palindrome partitioning of s.

class Solution {
public:
  bool isPalindrome(const string& s) {
      for(int i = 0; i < s.size()/2; ++i)
          if(s[i]!=s[s.size()-i-1])   return false;
      return true;
  }

  int minCut(string s) {
      int n = s.size();
      if(isPalindrome(s)) return 0;
      vector<vector<bool> > p(n, vector<bool>(n));
      vector<vector<int> > c(n, vector<int>(n));
      for(int i = 0; i < n; ++i) {
          p[i][i] = true;
          c[i][i] = 0;
      }
      for(int l = 2; l <= n; ++l) {
          for(int i = 0; i <= n-l; ++i) {
              int j = i+l-1;
              if(j >= n) continue;
              if(l == 2) p[i][j] = s[i]==s[j];
              else p[i][j] = (s[i]==s[j] && p[i+1][j-1]);

              if(p[i][j]) c[i][j] = 0;
              else {
                  c[i][j] = n+1;
                  for(int k = i; k < j; ++k)
                    c[i][j] = min(c[i][j], c[i][k]+c[k+1][j]+1);
              }
          }
      }
      return c[0][n-1];
  }
};
