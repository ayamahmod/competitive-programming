//http://codeforces.com/problemset/problem/244/A
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n,k;
  cin >> n >> k;
  vector<int> vec(n*k+1, 0);
  vector<vector<int>> vec2(k+1);
  for(int i = 1; i <= k ; ++i){
    int a;
    cin >> a;
    vec[a] = i;
  }
  int seg_cntr = 1;
  int curr_child = 1;
  for(int i = 1; i<= (n*k); ++i){
    if(seg_cntr >= n){
      seg_cntr = 1;
      ++curr_child;
    }
    if(!vec[i] && seg_cntr < n) {
      vec[i] = curr_child;
      ++seg_cntr;
    }
    vec2[vec[i]].push_back(i);
  }
  for(int i = 1; i <= k; ++i){
    for(int j = 0; j < vec2[i].size(); ++j){
      cout << vec2[i][j];
      if(j < vec2[i].size()-1)
        cout << ' ';
    }
    cout << endl;
  }
  return 0;
}
