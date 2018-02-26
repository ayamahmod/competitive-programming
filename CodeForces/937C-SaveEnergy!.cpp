//http://codeforces.com/contest/937/problem/C
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  long long k, d, t;
  cin >> k >> d >> t;
  if(k%d == 0)
    cout << t << endl;
  else {
    long long cyc = ((k/d) + (bool)(k%d)) * d;
    long long off = cyc - k;
    double ont = k/(double)t, offt = off/(2.0*t);
    long long whole = 1/ (ont+offt);
    double rem = 1 - whole*(ont + offt);
    double rest = 0;
    if(rem <= ont){
      rest = (rem*t);
    }else {
      rest = k + ((rem-ont) * 2.0 * t);
    }
    cout << std::fixed;
    cout << std::setprecision(12);
    cout << cyc*whole + rest << endl;
  }
  return 0;
}
