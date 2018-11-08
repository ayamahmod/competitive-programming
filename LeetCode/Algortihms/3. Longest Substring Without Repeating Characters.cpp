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

///////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charsIdx(128, -1);
        int curLen = 0;
        int maxLen = 0;
        for(int i = 0; i < s.size(); ++i) {
            int currCharPos = (int)s[i];
            if (charsIdx[currCharPos] == -1) {
                charsIdx[currCharPos] = i;
                curLen += 1;
            } else {
                maxLen = max(maxLen, curLen);
                int temp = charsIdx[currCharPos];
                for (int j = 0; j < charsIdx.size(); ++j) {
                    if ((charsIdx[j] >= 0) && (charsIdx[j] <= temp)) {
                        charsIdx[j] = -1;
                        curLen -= 1;
                    }
                }
                charsIdx[currCharPos] = i;
                curLen += 1;
            }
        }
        maxLen = max(maxLen, curLen);
        return maxLen;
    }
};
