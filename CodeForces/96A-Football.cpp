//http://codeforces.com/problemset/problem/96/A
#include <iostream>
#include <string>
using namespace std;
int main(){
  string s;
  cin >> s;
  int counter = 1;
  bool isDang = false;
  for(int i = 1; i < s.size() && !isDang; ++i){
    ++counter;
    if(s[i] != s[i-1])
      counter = 1;
    isDang = counter >= 7 ? true : false;
  }
  if(isDang)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
