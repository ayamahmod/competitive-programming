//http://codeforces.com/problemset/problem/137/B
#include <iostream>
#include <set>
using namespace std;
int main(){
  int n;
  cin >> n;
  set<int> st;
  for(int i = 0; i < n; ++i){
    int x;
    cin >> x;
    if(x >= 1 && x <= n)
      st.insert(x);
  }
  cout << n-st.size() << endl;
  return 0;
}
