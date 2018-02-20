//http://codeforces.com/problemset/problem/200/B
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
  int n;
  cin>>n;
  double nomerator =0;
  for(int i=0; i<n; ++i){
    int x;
    cin>>x;
    nomerator += x/100.0;
  }
  cout << std::fixed << std::setprecision(4) << (nomerator/n)*100.0 << endl;
}
