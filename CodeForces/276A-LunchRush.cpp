//http://codeforces.com/problemset/problem/276/A
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int main() {
  int n, k, max_joy = INT_MIN;
  cin >> n >> k;
  for(int i = 0; i < n; ++i){
    int f, t, joy;
    cin >> f >> t;
    if(t > k)
    joy = f - ( t - k );
    else
      joy = f;
    max_joy = max(max_joy, joy);
  }
  cout << max_joy << endl;
  return 0;
}
