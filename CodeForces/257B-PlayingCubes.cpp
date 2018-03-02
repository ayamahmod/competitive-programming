//http://codeforces.com/problemset/problem/257/B
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  cout << max(n,m)-1 << ' ' << min(n,m) << endl;
  return 0;
}
