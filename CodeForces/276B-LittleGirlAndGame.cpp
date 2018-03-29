// http://codeforces.com/problemset/problem/276/B
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  string s;
  cin >> s;
  vector<int> v(26, 0);
  int cntr = 0;
  for(int i = 0; i < s.size(); ++i) {
    int idx = s[i] - 'a';
    ++v[idx];
    if(v[idx] %2 == 1)
      ++cntr;
    else
      --cntr;
  }
  if(cntr %2 || cntr == 0)
    cout << "First" << endl;
  else
    cout << "Second" << endl;
  return 0;
}
