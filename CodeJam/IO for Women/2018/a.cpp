#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int T;
  cin >> T;
  for(int i=1; i<= T; ++i){
    int K;
    cin>> K;
    vector<int> vec(K, 0);
    for(int j=0; j<K; j++){
      cin>>vec[j];
    }
    sort(vec.begin(), vec.end());
    unsigned long long result =0;
    int m=0, n=1;
    if(K %2 ==0){
      for(int j =0; j<= ((K/2)-1) ; ++j){
        result += (vec[m]-j)*(vec[m]-j) + (vec[n]-j)*(vec[n]-j);
        m+=2; n+=2;
      }
    }else{
      for(int j =0; j<= (((K-1)/2)-1) ; ++j) {
        result += (vec[m]-j)*(vec[m]-j) + (vec[n]-j)*(vec[n]-j);
        m+=2; n+=2;
      }
      result += (vec[m]- ((K-1)/2))*(vec[m]- ((K-1)/2));
    }
    cout << "Case #"<<i<<": "<< result <<endl;
  }
  return 0;
}
