//http://codeforces.com/problemset/problem/236/A
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  vector<int> vec(26,0);
  string s;
  cin >> s;
  int distinct_chars = 0;
  for(int i = 0; i < s.size(); ++i){
    if(!vec[s[i]-'a']++)
      ++distinct_chars;
  }
  if(distinct_chars%2)
    cout << "IGNORE HIM!" << endl;
  else
    cout << "CHAT WITH HER!" << endl;
  return 0;
}
