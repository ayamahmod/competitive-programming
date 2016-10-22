class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> m;
        int ans=0;
        for(int i=0, j=0;j<s.size();j++){
          if( m.find(s[j]) != m.end() )
            i=max(m[s[j]],i);
          ans=max(ans, j-i+1);
          m[s[j]]=j+1;
        }
        return ans;
    }
};
