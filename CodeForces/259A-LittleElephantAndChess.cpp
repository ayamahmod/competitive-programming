//http://codeforces.com/problemset/problem/259/A
#include <iostream>
#include <string>
using namespace std;
bool isValidRow(string& s){
  char old = -1, curr = -1 ;
  bool double_right = false, double_left = false;
  for(int i = 0; i < s.size(); ++i){
    old = curr;
    curr = s[i];
    if(old == curr){
      if(i == 1 && s[s.size()-1] != s[i])
        double_left = true;

      else if(i == s.size()-1 && s[i] != s[0])
        double_right = true;

      else
        return false;
    }
  }
  return true;
}

int main(){
  bool cond = true;
  for(int i = 0; i < 8; ++i){
    string s;
    cin >> s;
    cond = cond && isValidRow(s);
  }
  if(cond)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
