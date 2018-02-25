//http://codeforces.com/problemset/problem/401/A
#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int n, x;
  cin >> n >> x;
  int result = 0;
  for(int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    result += temp;
  }
  result = abs(result);
  int cards = result%x ? result/x+1:result/x;
  cout << cards << endl;
  return 0;
}
