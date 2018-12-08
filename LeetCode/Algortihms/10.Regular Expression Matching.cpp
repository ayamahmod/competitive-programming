/*
Given an input string (s) and a pattern (p),
implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.

*/
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.length()==0)
          return (s.length()==0);
        if(p.length()==1 || p[1]!='*'){
          if(s.length()<1)  return false;
          else if (p[0]!=s[0] && p[0]!='.')   return false;
          else return isMatch(s.substr(1),p.substr(1));
        }
        else{
          if(isMatch(s,p.substr(2)))  return true;
          int i=0;
          while(i<s.length() && (s[i]==p[0] || (p[0]=='.')){
            if(isMatch(s.substr(i+1), p.substr(2)))   return true;
            i++;
          }
          return false;
        }
    }
};

// second Solution
class Solution {
public:
    bool isMatch(string s, string p) {
        return match(s, 0, p, 0);
    }

    bool matchChar(char c, char p) {
        return p == '.' || c == p;
    }

    bool match(string& s, int s1, string& p, int s2) {
        if(s1 >= s.size() && s2 >= p.size())    return true;
        if(s2 >= p.size())    return false;
        if(s1 >= s.size()) {
            for(int i = s2; i < p.size(); i+=2) {
                if(p[i+1] != '*') return false;
            }
            return true;
        }
        if(s2 < p.size()-1 && p[s2+1] == '*') { // wildcard matching
            bool cond = match(s, s1, p, s2+2);
            for(int i = s1; i < s.size() && matchChar(s[i], p[s2]) && !cond; ++i) {
                cond |= match(s, i+1, p, s2+2);
            }
            return cond;
        }else {
            if(matchChar(s[s1], p[s2]))
                return match(s, s1+1, p, s2+1);
            return false;
        }
    }
};
