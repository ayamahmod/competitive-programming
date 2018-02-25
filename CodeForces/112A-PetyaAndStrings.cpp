//http://codeforces.com/problemset/problem/112/A
#include <iostream>
#include <string>
using namespace std;
int main(){
  string s1, s2;
  cin >> s1 >> s2;
  int min_length = min(s1.size(), s2.size());
  bool cond = true;
  for(int i = 0; i < min_length && cond; ++i){
    char c1 = tolower(s1[i]), c2 = tolower(s2[i]);
    if(c1 < c2) {
      cout << -1 << endl;
      cond = false;
    }
    else if(c1 > c2) {
      cout << 1 << endl;
      cond = false;
    }
  }
  if(cond){
    if(s1.size() < s2.size())
      cout << -1 << endl;
    else if(s1.size() == s2.size())
      cout << 0 << endl;
    else
      cout << 1 << endl;
  }
  return 0;
}
