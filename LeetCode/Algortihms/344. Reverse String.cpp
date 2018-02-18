class Solution {
public:
    string reverseString(string s) {
        string s2="";
        for(int i=s.size(); i>=0; i--)
            s2.append(s,i,1);
        return s2;
    }
};
