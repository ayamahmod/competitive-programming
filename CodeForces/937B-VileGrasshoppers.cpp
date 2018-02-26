//http://codeforces.com/contest/937/problem/B
#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int p, y;
  cin >> p >> y;
  int x = -1;
  for(int i = y; i > p; --i){
    int square_root = (int) sqrt(i) + 1;
    bool cond = true;
    for (int j = 2; j < square_root && cond; ++j) {
        if (i % j == 0 && (j <= p || i/j <= p))
            cond = false;
    }
    if(cond){
      x = i;
      break;
    }
  }

  cout << x <<endl;

  return 0;
}
