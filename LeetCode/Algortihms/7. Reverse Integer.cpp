#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    int Out_of_Limits(int toggle){
      if(toggle==1)
        return INT_MAX;
      return INT_MIN;
    }
    int myAtoi(string str) {
        if(str.size()==0)   return 0;
        long y=0;
        int start=0;
        int toggle=1;
        while(str[start]==' ')  start++;
        if(str[start]=='-')
            toggle*=-1;
        if(str[start]=='-' || str[start]=='+')
            start++;
        for(int i=start;i<str.size();i++){
            if(str[i]>='0' && str[i]<='9'){
                int temp=y*10;
                if(temp/10 !=y) return Out_of_Limits(toggle);
                temp+=(str[i]-'0');
                if(temp<0)  return Out_of_Limits(toggle);
                y=temp;
            }
            else
                break;
        }
        return y*toggle;
    }
};

int main()
{
  Solution S;
  cout<<S.myAtoi("    10522545459")<<endl;
}
