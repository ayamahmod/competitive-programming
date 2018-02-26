//http://codeforces.com/contest/937/problem/A
#include <iostream>
#include <set>
using namespace std;
int main(){
  int n;
  cin >> n;
  set<int> s;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    s.insert(x);
  }
  if(s.find(0) != s.end())
    cout << s.size()-1 << endl;
  else
    cout << s.size() << endl;
  return 0;
}
