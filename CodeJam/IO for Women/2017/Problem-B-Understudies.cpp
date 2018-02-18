#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
int main() {
  int T,P;
  cin>>T;
  for(int i = 1; i <= T; ++i){
    cin>>P;
    vector<long double> vec_prob(2*P, 0.0);
    for(int j = 0; j < 2*P; ++j){
      long double x;
      cin >> x;
      vec_prob[j] = x;
    }
    sort(vec_prob.begin(), vec_prob.end());
    long double result = 1.0l;
    for(int j = 0,k = vec_prob.size()-1; j < k; j++,k--){
        result *= (1.0l-vec_prob[j]*vec_prob[k]);
    }
    cout << "Case #"<<i<<": "<< std::fixed << std::setprecision(6) << result <<endl;
  }
  return 0;
}
