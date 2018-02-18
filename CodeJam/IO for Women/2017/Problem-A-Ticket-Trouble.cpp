#include <iostream>
#include <map>
#include <set>
using namespace std;
int main() {
  int T,F,S;
  cin>>T;
  for(int i=1; i<=T; ++i){
    cin>>F>>S;
    int a,b;
    set<pair<int,int> > S;
    for(int j=0; j<F; ++j){
      cin>>a>>b;
      S.insert(make_pair(a,b));
    }
    map<int,int> p;
    int max_row = 0;
    for(auto& j: S){
      max_row = max_row < ++p[j.first] ? p[j.first]:max_row;
      if(j.first != j.second)
        max_row = max_row < ++p[j.second] ? p[j.second]:max_row;
    }
    cout<<"Case #"<<i<<": "<<max_row<<endl;
  }
  return 0;
}
