#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
void findManager(const int& j, vector<pair<int,int> >& vec, vector<int>& managed){
  for(int i = j+1; i<vec.size(); ++i) {
    managed[i] = max(0, managed[i]-vec[j].second);
    vec[j].second-= managed[i];
    if(vec[j].second <= 0) {
      vec[j].second = 0;
      return;
    }
  }
}

int findCEO_Managed(const vector<pair<int,int> >& vec) {
  int ceo_managed=0;
  for(int i=vec.size()-1;i>=0;i--){
    ceo_managed+=vec[i].second;
  }
  return ceo_managed;
}

int main(){
  int T;
  cin>>T;
  for(int i=1; i<=T; ++i){
    int min_ceo_level, L;
    cin >> L;
    vector<pair<int,int> > vec(L);
    vector<int> managed(L);
    for(int j=0; j<L; ++j){
      int N, E;
      cin>> N >> E;
      vec[j]=make_pair(E, N);
      managed[j]=E*N;
    }
    for(int j=0; j< vec.size(); j++){
      findManager(j, vec, managed);
    }
    min_ceo_level = max(findCEO_Managed(vec), (vec[vec.size()-1].first+1));
    cout<<"Case #"<<i<<": "<<min_ceo_level<<endl;
  }
  return 0;
}
