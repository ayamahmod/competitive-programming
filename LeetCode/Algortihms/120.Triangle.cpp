// Given a triangle, find the minimum path sum from top to bottom.
// Each step you may move to adjacent numbers on the row below.
// For example, given the following triangle
//
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
// Note:
//
// Bonus point if you are able to do this using only O(n) extra space,
// where n is the total number of rows in the triangle.

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
    vector<vector<int> > dp;
    for(int i = 0; i < triangle.size(); ++i) {
        dp.push_back(vector<int>(triangle[i].size()));
        for(int j = 0; j < triangle[i].size(); ++j) {
            dp[i][j] = triangle[i][j];
            if(i==0) continue;
            else if(j==0) dp[i][j] += dp[i-1][j];
            else if(j >= triangle[i-1].size()) dp[i][j] += dp[i-1][j-1];
            else dp[i][j] += min(dp[i-1][j], dp[i-1][j-1]);
        }
    }
    int minPathSum = -1; bool initialized = false;
    for(int j = 0; j < dp[dp.size()-1].size(); ++j) {
        if(!initialized || dp[dp.size()-1][j] < minPathSum)
        { minPathSum = dp[dp.size()-1][j];  initialized = true; }
    }
    return minPathSum;
}

};

//O(n) space
class Solution {
public:
  int minimumTotal(vector<vector<int> >& triangle) {
    vector<int> prev, curr;
    for(int i = 0; i < triangle.size(); ++i) {
        curr.resize(triangle[i].size());
        for(int j = 0; j < triangle[i].size(); ++j) {
            curr[j] = triangle[i][j];
            if(i==0) continue;
            else if(j==0) curr[j] += prev[j];
            else if(j >= triangle[i-1].size()) curr[j] += prev[j-1];
            else curr[j] += min(prev[j], prev[j-1]);
        }
        prev = curr;
    }
    int minPathSum = -1; bool initialized = false;
    for(int j = 0; j < curr.size(); ++j) {
        if(!initialized || curr[j] < minPathSum)
        { minPathSum = curr[j];  initialized = true; }
    }
    return minPathSum;
  }
};



// Second Solution

class Solution {
public:
    /**
     * @param triangle: a list of lists of integers
     * @return: An integer, minimum path sum
     */
    int minimumTotal(vector<vector<int>> &triangle) {
        // write your code here
        vector<int> v = triangle[triangle.size()-1];
        for(int i = triangle.size()-2; i >= 0; --i) {
            for(int j = 0; j < triangle[i].size(); ++j) {
                v[j] = triangle[i][j] + min(v[j], v[j+1]);
            }
        }
        return v[0];
    }
};
