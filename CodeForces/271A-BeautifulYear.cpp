#include <iostream>
#include <vector>
using namespace std;

bool isDistinctYear(const int& year){
  vector<bool> vec(10,0);
  int x = year;
  while(x){
    int y = x%10;
    x /= 10;
    if(vec[y])
      return false;
    vec[y] = true;
  }
  return true;
}

int main(){
  int year;
  cin >> year;
  while(1){
    if(isDistinctYear(++year))
      break;
  }
  cout << year << endl;
  return 0;
}
