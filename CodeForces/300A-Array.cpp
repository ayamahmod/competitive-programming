//http://codeforces.com/problemset/problem/300/A
#include <iostream>
#include <vector>
using namespace std;

void printArr(const vector<int>& v){
  cout << v.size();
  for(int i = 0; i < v.size(); ++i)
    cout << ' ' << v[i];
  cout << endl;
}

int main(){
  int n;
  cin >> n;
  vector<int> vneg, vpos, vzero;
  for(int i = 0; i < n; ++i){
    int x;
    cin >> x;
    if(x > 0) vpos.push_back(x);
    else if(x == 0) vzero.push_back(x);
    else if(x < 0) vneg.push_back(x);
  }

  if(vpos.size() == 0){
    vpos.push_back(vneg[vneg.size()-1]);
    vpos.push_back(vneg[vneg.size()-2]);
    vneg.erase(vneg.begin()+vneg.size()-1);
    vneg.erase(vneg.begin()+vneg.size()-1);
  }

  if(vneg.size() % 2 == 0){
    vzero.push_back(vneg[vneg.size()-1]);
    vneg.erase(vneg.begin()+vneg.size()-1);
  }

  printArr(vneg);
  printArr(vpos);
  printArr(vzero);
  return 0;
}
