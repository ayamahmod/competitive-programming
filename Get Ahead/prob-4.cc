// Given an array of non-negative integers that represent the bars (y value)
// in a histogram (with the array index being the x value),
// find the rectangle with the largest area under the curve and above the axis.
 // the pair of array indices that represent the rectangle.
//
// Test Cases
//
// Note that there may be other valid answers.
//
// For array [2,4,2,1], largest area is 6, with height 2, and width from indices 0 to 2.
//
// For array [2,4,2,1,10,6,10] the largest area is 18, with height 6 and width from indices 4 to 6.
//

int largestRectHistogram(vector<int> hist) {
  int largestRect = 0, i = 0;
  stack<int> st;
  while(i < hist.size()) {
    if(st.empty() || hist[st.top()] <= hist[i]) {
      st.push(i);
    } else {
      int tp = st.top();
      st.pop();
      int w = st.empty() ? i:i-st.top()-1;
      largestRect = max(largestRect, w*hist[tp]);
    }
  }
  while(!st.empty()) {
    int tp = st.top();
    st.pop();
    int w = st.empty() ? i:i-st.top()-1;
    largestRect = max(largestRect, w*hist[tp]);
  }
  return largestRect;
}
