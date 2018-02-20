//http://codeforces.com/contest/935/problem/A
#include <iostream>
using namespace std;
int main() {
  int n;
  cin>>n;
  int no_ways=0;
  for(int i=1;i<= n/2; i++){
    if((n-i)%i == 0)
      ++no_ways;
  }
  cout<<no_ways<<endl;
  return 0;
}
