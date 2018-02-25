//http://codeforces.com/problemset/problem/330/A
#include <iostream>
#include <set>
using namespace std;
int main() {
  int r, c;
  cin >> r >> c;
  int num_good_rows = 0;
  set<int> bad_columns;
  for(int i = 0; i < r; ++i){
    bool good_row = true;
    for(int j = 0; j < c; ++j){
      char x;
      cin >> x;
      if(x == 'S'){
        good_row = false;
        bad_columns.insert(j);
      }
    }
    if(good_row)  ++num_good_rows;
  }
  int num_good_columns = c-bad_columns.size();
  cout << (num_good_rows*c+num_good_columns*r)-num_good_rows*num_good_columns << endl;
  return 0;
}
