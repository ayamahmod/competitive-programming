//http://codeforces.com/problemset/problem/313/A
#include <iostream>
using namespace std;
int main(){
  int x;
  cin >> x;
  if(x < 0) {
    int last = -x%10, before_last = -(x/10)%10;
    int smaller = min(last, before_last);
    x= (x/100)*10-smaller;
  }
  cout << x << endl;
  return 0;
}
