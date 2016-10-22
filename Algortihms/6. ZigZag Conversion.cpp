#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)  return s;
        vector<string> v(numRows,"");
        int row=0,toggle=1;
        for(int i=0;i<s.size();i++){
            v[row].append(s,i,1);
            row+=toggle;
            //if(row<0 || row>=numRows)   row=0;
            if(row==numRows-1 || row==0)
                toggle*=-1;
        }
        string newS="";
        for(int i=0; i<v.size(); i++)
            newS.append(v[i]);
        return newS;
    }
};

int main()
{
  Solution S;
  cout<<S.convert("AB",2)<<endl;
}
