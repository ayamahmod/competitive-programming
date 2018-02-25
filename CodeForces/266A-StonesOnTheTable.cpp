//http://codeforces.com/problemset/problem/266/A
#include <iostream>
using namespace std;
int main() {
  int n, num = 0;
  cin >> n;
  char prev = -1, next = -1;
  for(int i = 0; i < n; ++i){
    cin >> next;
    if(next == prev)
      ++num;
    prev = next;
  }
  cout << num << endl;
  return 0;
}
