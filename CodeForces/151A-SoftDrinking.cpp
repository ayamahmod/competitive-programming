//http://codeforces.com/problemset/problem/151/A
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  cout << min(min((k*l)/nl, c*d), p/np)/n << endl;
  return 0;
}
