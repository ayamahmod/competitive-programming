//http://codeforces.com/problemset/problem/339/B
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  unsigned int st = 1;
  long long counter = 0;
  for(int i = 0; i < m; ++i){
    int x;
    cin >> x;
    if(x >= st)
      counter += x-st;
    else{
      counter += n - st + x;
    }
    st = x;
  }
  cout << counter << endl;
  return 0;
}
