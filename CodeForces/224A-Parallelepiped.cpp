//http://codeforces.com/problemset/problem/224/A
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  vector<int> v(3);
  cin >> v[0] >> v[1] >> v[2];
  sort(v.begin(), v.end());
  for(int i = 1; i < sqrt(v[0])+1; ++i){
    if(v[0]%i== 0 && (v[1]%i==0 || v[1]%(v[0]/i)==0)){
      int common_edge = v[1]%i==0 ? i:v[1]/i;
      int edge1 = v[0]/common_edge, edge2 = v[1]/common_edge;
      if(edge1*edge2 == v[2]){
        cout << 4*edge1 + 4*edge2 + 4*common_edge << endl;
        break;
      }
    }
  }
  return 0;
}
