//http://codeforces.com/problemset/problem/320/A
#include <iostream>
#include <string>
using namespace std;
int main(){
  string s;
  cin >> s;
  bool cond = true;
  for(int i = 0; i < s.size() && cond; ){
    if(s.substr(i, 3) == "144")
      i += 3;
    else{
      if(s.substr(i, 2) == "14")
        i += 2;
      else{
        if(s.substr(i, 1) == "1")
          i += 1;
        else
          cond = false;
      }
    }
  }
  if(cond)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
