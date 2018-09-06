#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

// Given a string of parentheses, find the size of the longest continuous
// substring of balanced parenthesis. Parentheses are considered balanced when
// there is a valid closing parenthesis for an opening one.
//
// Test Cases
//
// Note that there may be other valid answers.
//
// For parentheses "())(())", the longest continuous set would be 4
// characters long (the last 4 characters of the input)
//
// For ")(()))))((((()" , the max length would be 4

int first_soln(string s) {
  int left_paren = 0;
  int longest_substring = 0;
  int curr_substring = 0;
  for(int i = 0; i < s.size(); ++i) {
    if(s[i] == '(' )  ++left_paren;
    else if(s[i] == ')') {
      if(left_paren) {
        curr_substring += 2;
        --left_paren;
      } else {
        longest_substring = max(longest_substring, curr_substring);
        curr_substring = 0;
      }
    }
  }
  return max(curr_substring, longest_substring);
}

int second_soln(string s) {
  stack<char> st;
  int longest_substring = 0;
  int curr_substring = 0;
  for(int i = 0; i < s.size(); ++i) {
    if(s[i] == '(') st.push(s[i]);
    else if(s[i] == ')') {
      if(st.size()) {
        curr_substring +=2;
        st.pop();
      }
      else {
        longest_substring = max(longest_substring, curr_substring);
        curr_substring = 0;
      }
    }
  }
  return max(curr_substring, longest_substring);
}

int main() {
  string s;
  getline(cin, s);
  cout << second_soln(s) << endl;
  return 0;
}
