#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height){
        int maxArea=0,l=0,r=height.size()-1;
        while(l!=r){
          maxArea=max(maxArea, (r-l)*min(height[l], height[r]));
          if(height[l]<height[r]) l++;
          else  r--;
        }
        return maxArea;
  }
};

int main()
{
  vector<int> arr(2,1);
  Solution S;
  cout<<S.maxArea(arr)<<endl;
  return 0;
}
