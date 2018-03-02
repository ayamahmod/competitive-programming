//http://codeforces.com/problemset/problem/242/B
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

int main(){
  int n;
  cin >> n;
  int minX = INT_MAX, maxY = 0, idx = -1;
  for(int i = 0; i < n; ++i){
    int x, y;
    cin >> x >> y;
    if(x <= minX && y >= maxY){
      minX = x; maxY=y;
      idx = i+1;
    }else if(x < minX){
      minX = x;
      idx = -1;
    }else if(y > maxY){
      maxY = y;
      idx = -1;
    }
  }

  cout << idx << endl;
  return 0;
}
