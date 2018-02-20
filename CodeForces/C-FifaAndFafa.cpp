//http://codeforces.com/contest/935/problem/C
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
  int R, x1, y1, x2, y2;
  cin >> R >> x1 >> y1 >> x2 >> y2;
  long long dist_sqrd = (x1-x2) * 1LL * (x1-x2) + (y1-y2) * 1LL * (y1-y2);
  double x3, y3, r;
  if(dist_sqrd >= R * 1LL * R) {
    x3 = x1;
    y3 = y1;
    r = R;
  } else if(dist_sqrd == 0) {
    x3 = (x1+(R/2.0));
    y3 = y1;
    r = (R/2.0);
  } else {
    double dist = sqrt(dist_sqrd);
    r = (dist + R) /2;
    x3 = (x1-x2)* r/dist + x2;
    y3 = (y1-y2)* r/dist + y2;
  }
  cout << std::fixed << std::setprecision(6) << x3 << ' ';
  cout << std::fixed << std::setprecision(6) << y3 << ' ';
  cout << std::fixed << std::setprecision(6) << r << endl;
  return 0;
}
