//http://codeforces.com/problemset/problem/239/A
#include <iostream>
#include <vector>
using namespace std;
int main(){
  int y, k, n;
  cin >> y >> k >> n;
  vector<int> v;
  for(int i = y/k; i <= n/k; ++i){
    int x = i*k - y;
    if(x > 0) v.push_back(x);
  }
  bool isFirst = true;
  for(int i = 0; i < v.size(); ++i){
    if(!isFirst)  cout << ' ';
    cout << v[i];
    isFirst = false;
  }
  if(v.size() == 0)
    cout << -1;
  cout << endl;
  return 0;
}
