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
