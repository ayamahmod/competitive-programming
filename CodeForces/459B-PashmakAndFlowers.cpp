//http://codeforces.com/problemset/problem/459/B
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main(){
  unsigned long long n;
  cin >> n;
  unsigned long long minX = ULLONG_MAX, num_min = 0, maxX = 0, num_max = 0, count;
  for(int i = 0; i < n; ++i){
    int x;
    cin >> x;
    if(x < minX){
      minX = x;
      num_min = 1;
    } else if(x == minX){
      ++num_min;
    }
    if(x > maxX){
      maxX = x;
      num_max = 1;
    } else if(x == maxX){
      ++num_max;
    }
  }
  count = num_min * num_max;
  if(minX == maxX){
    count = (n* (n-1))/2;
  }
  cout << maxX - minX << ' ' << count << endl;
  return 0;
}
