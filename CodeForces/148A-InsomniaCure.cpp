//http://codeforces.com/problemset/problem/148/A
#include <iostream>
using namespace std;

int gcd(int a, int b){
  return b == 0 ? a:gcd(b, a%b);
}

int lcm(int a, int b){
  return a / gcd(a, b) * b;
}

int main(){
  int k, l, m, n, d;
  cin >> k >> l >> m >> n >> d;
  int result = d/k + d/l + d/m + d/n;
  result -= d/lcm(k, l);
  result -= d/lcm(k, m);
  result -= d/lcm(k, n);
  result -= d/lcm(l, m);
  result -= d/lcm(l, n);
  result -= d/lcm(m, n);
  result += d/lcm(lcm(k, l), m);
  result += d/lcm(lcm(k, l), n);
  result += d/lcm(lcm(l, m), n);
  result += d/lcm(lcm(k, m), n);
  result -= d/lcm(lcm(k, l), lcm(m, n));
  cout << result << endl;

  return 0;
}
