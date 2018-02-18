class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string str(2*n,' ');
        vector<string> v;
        InsertParenthesis(v, str, 0, n, n);
        return v;
    }
    void InsertParenthesis(vector<string>& v, string& str, int i, int nleft, int nright){
        if(nleft<0 || nright<0 || nright<nleft)     return;
        if(nleft==0 && nright==0)   v.push_back(str);
        else{
            str[i]='(';
            InsertParenthesis(v, str, i+1, nleft-1, nright);
            str[i]=')';
            InsertParenthesis(v, str, i+1, nleft, nright-1);
        }
    }
};
