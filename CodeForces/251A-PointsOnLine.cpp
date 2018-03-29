// http://codeforces.com/problemset/problem/251/A
#include <iostream>
#include <vector>
using namespace std;
int search(const vector<int>& v, const int& x, int l, int r) {
    int predecessor = -1;
    while(l <= r) {
      int mid = (l + r)/2;
      if(v[mid] <= x) {
        predecessor = mid;
        l = mid+1;
      }
      else {
        r = mid-1;
      }
    }
    return predecessor;
}


int main() {
  int n, d;
  cin >> n >> d;
  vector<int> v(n);
  for(int i = 0; i < n; ++i)
    cin >> v[i];
  unsigned long long sum = 0;
  for(int i = 0; i < n-2; ++i) {
    int j = search(v, v[i] + d, i+2, n-1);
    if(j != -1)
      sum += (long long)(j-i)*(j-i-1)/2;
  }
  cout << sum << endl;
  return 0;
}
