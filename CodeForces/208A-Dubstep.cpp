//http://codeforces.com/problemset/problem/208/A
#include <iostream>
#include <string>
using namespace std;
int main(){
  string s1, s2;
  cin >> s1;
  for(int i = 0; i < s1.size(); ){
    std::size_t found = s1.find("WUB", i);
    if(s2.size() != 0)
      s2 += ' ';
    if (found!=std::string::npos){
      s2 += s1.substr(i, found - i);
      i = found+3;
    }
    else{
      s2 += s1.substr(i);
      break;
    }
  }
  cout << s2 << endl;
  return 0;
}
