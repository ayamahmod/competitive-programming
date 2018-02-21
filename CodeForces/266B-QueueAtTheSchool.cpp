//http://codeforces.com/problemset/problem/266/B
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, t;
  cin >> n >> t;
  vector<char> vec(n);
  for(int i = 0; i < n; ++i){
    cin >> vec[i];
  }
  for(int i = 1; i <= t; ++i){
    for(int j = 0; j < n-1;){
      if(vec[j] == 'B' && (j+1) < n && vec[j+1] == 'G'){
        vec[j] = 'G';
        vec[j+1] = 'B';
        j+=2;
      } else
        ++j;
    }
  }
  for(int j = 0; j < n; j++)
    cout << vec[j];
  cout << endl;
  return 0;
}
