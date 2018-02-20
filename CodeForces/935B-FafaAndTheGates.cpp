//http://codeforces.com/contest/935/problem/B
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int isCrossing(const pair<int,int>& a, const pair<int,int>& b){
  if(b.second-a.second == 0 || b.first-a.first == 0)
    return 1;
  return 0;
}

int main() {

  int n;
  cin>>n;
  char c;
  int x=0, y=0, to_be_paid=0;
  vector<pair<int,int> > vec(n);
  vector<int> indices;
  for(int i=0;i<n;++i){
    cin>>c;
    if(c=='U'){
      ++y;
    }else if(c=='R'){
      ++x;
    }
    vec[i] = make_pair(x,y);
    if(x==y)  indices.push_back(i);
  }
  for(int i=0;i<indices.size();++i){
    if(indices[i]-1 >=0 && indices[i]+1<vec.size())
      to_be_paid+=isCrossing(vec[indices[i]-1], vec[indices[i]+1]);
  }
  cout<<to_be_paid<<endl;
  return 0;
}
