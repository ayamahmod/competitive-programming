// http://codeforces.com/problemset/problem/349/A
#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long n25 = 0, n50 = 0, n100 = 0;
  bool canSell = true;
  for(int i = 0; i < n && canSell; ++i) {
    int x;
    cin >> x;
    if(x == 25) {
      ++n25;
    } else if(x == 50 && n25 >= 1) {
      --n25;
      ++n50;
    } else if(x == 100 && n25 >= 1 && n50 >= 1) {
      --n25;
      --n50;
      ++n100;
    } else if(x == 100 && n25 >= 3) {
      n25 -= 3;
      ++n100;
    } else {
      canSell = false;
    }
  }
  if(canSell)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
