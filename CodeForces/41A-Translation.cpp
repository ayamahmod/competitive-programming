//http://codeforces.com/problemset/problem/41/A
#include <iostream>
#include <string>
using namespace std;
int main(){
  string s1, s2;
  cin >> s1 >> s2;
  bool equal = true;
  if(s1.size() != s2.size())
    equal = false;
  for(int i = 0, j = s2.size()-1; i < s1.size(), j >= 0 && equal; ++i, --j){
      if(s1[i] != s2[j])
        equal = false;
  }
  if(equal)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
