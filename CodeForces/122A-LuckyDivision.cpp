#include <iostream>
#include <cmath>
using namespace std;
bool isLucky(int n){
  while(n){
    int x = n%10;
    if(x != 4 && x != 7){
      return false;
    }
    n/=10;
  }
  return true;
}
bool factorize(int n){
  for(int i = 2; i < sqrt(n)+1; ++i){
    if(n%i == 0){
      if(isLucky(i) || isLucky(n/i))
        return true;
    }
  }
  return false;
}

int main(){
  int n;
  cin >> n;
  if(isLucky(n) || factorize(n))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
