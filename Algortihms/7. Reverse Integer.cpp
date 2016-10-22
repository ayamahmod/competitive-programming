#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long y=0;
        while(x){
            y=10*y+x%10;
            if (y>INT_MAX || y<INT_MIN)  return 0;
            x/=10;
        }
        return y;
    }
};

int main()
{
  Solution S;
  cout<<S.reverse(1534236469)<<endl;
}
