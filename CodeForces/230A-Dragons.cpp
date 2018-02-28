//http://codeforces.com/problemset/problem/230/A
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int s, n;
  cin >> s >> n;
  vector<pair<int, int> > v(n);
  for(int i = 0; i < n; ++i)
    cin >> v[i].first >> v[i].second;

  sort(v.begin(), v.end());
  bool canMove = true;
  for(int i = 0; i < n && canMove; ++i){
    if(s > v[i].first)
      s+= v[i].second;
    else
      canMove = false;
  }
  if(canMove)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
