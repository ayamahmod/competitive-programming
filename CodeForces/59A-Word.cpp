//http://codeforces.com/problemset/problem/59/A
#include <iostream>
#include <string>
#include <locale>
using namespace std;
int main() {
  string s;
  cin >> s;
  int num_lower = 0, num_upper = 0;
  for(int i = 0; i < s.size(); ++i){
    if(s[i] >= 97)
      ++num_lower;
    else
      ++num_upper;
  }
  if(num_lower >= num_upper){
    for(int i = 0; i < s.size(); ++i)
      s[i]=tolower(s[i]);
  }
  else{
    for(int i = 0; i < s.size(); ++i)
      s[i]=toupper(s[i]);
  }
  cout << s << endl;
  return 0;
}
