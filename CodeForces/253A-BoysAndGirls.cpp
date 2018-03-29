// http://codeforces.com/problemset/problem/253/A
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int n, m;
  cin >> n >> m; // n boys and m girls
  string s = "";
  char a = 'B', b = 'G';
  if( n < m) {
    a = 'G';
    b = 'B';
  }
  int bigN = max(n, m), smallN = min(n, m);
  int i = 0;
  for(; i < smallN; i++) {
    s += a;
    s += b;
  }
  while(i < bigN) {
    s += a;
    ++i;
  }
  cout << s << endl;
  return 0;
}
