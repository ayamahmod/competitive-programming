//http://codeforces.com/problemset/problem/152/A
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> highest_mark(m, 0);
  vector<vector<int> > vec(m);
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      char c;
      cin >> c;
      int grade = c-'0';
      if(grade > highest_mark[j]){
        vec[j].clear();
        vec[j].push_back(i);
        highest_mark[j] = grade;
      }
      else if(grade == highest_mark[j])
        vec[j].push_back(i);
    }
  }
  set<int> st;
  for(int i = 0; i < m; ++i)
    for(int j = 0; j < vec[i].size(); ++j)
      st.insert(vec[i][j]);

  cout << st.size() << endl;

  return 0;
}
