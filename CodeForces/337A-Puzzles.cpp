//http://codeforces.com/problemset/problem/337/A
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> v(m);
  for(int i = 0; i < m; ++i)
    cin >> v[i];
  sort(v.begin(), v.end());
  int min_diff = INT_MAX;
  for(int i = 0; i < m && i+n <= m; ++i)
    min_diff = min(min_diff, v[i+n-1]-v[i]);
  cout << min_diff << endl;
  return 0;
}
