class Solution {
private:
    vector<string> v;
public:
    Solution(){
        v.push_back("abc");
        v.push_back("def");
        v.push_back("ghi");
        v.push_back("jkl");
        v.push_back("mno");
        v.push_back("pqrs");
        v.push_back("tuv");
        v.push_back("wxyz");
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="")  return {};
        vector<string> vec;
        AddLetters(digits, 0, "", vec);
        return vec;
    }
    void AddLetters(string& digits,int itr, string curr, vector<string>& vec){
        if(itr==digits.size())   {vec.push_back(curr);  return;}
        int idx=digits[itr]-'2';
        for(int i=0;i<v[idx].size();i++)
          AddLetters(digits, itr+1, curr+v[idx][i], vec);
    }
};
