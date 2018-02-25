//http://codeforces.com/problemset/problem/116/A
#include <iostream>
using namespace std;
int main(){
  int n, passengers = 0, capacity = 0;
  cin >> n;
  for(int i = 0; i < n; ++i){
    int a, b;
    cin >> a >> b;
    passengers -=a;
    passengers += b;
    capacity = max(capacity, passengers);
  }
  cout << capacity << endl;
  return 0;
}
