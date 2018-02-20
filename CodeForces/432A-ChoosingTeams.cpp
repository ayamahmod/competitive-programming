//http://codeforces.com/problemset/problem/432/A
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int n,k;
  cin>>n>>k;
  vector<int> vec(n);
  for(int i=0; i<n; ++i)
    cin>>vec[i];
  int result = 0;
  sort(vec.begin(), vec.end());
  for(int i=0; i < vec.size() && (i+2) < vec.size(); i+=3){
    if((vec[i]+k)<=5 && (vec[i+1]+k)<=5 && (vec[i+2]+k)<=5){
      ++result;
    }
  }
  cout << result <<endl;
  return 0;
}
