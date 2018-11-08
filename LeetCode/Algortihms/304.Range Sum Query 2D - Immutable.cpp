// Given a 2D matrix matrix, find the sum of the elements inside the rectangle
// defined by its upper left corner (row1, col1) and lower right corner (row2,
// col2).

class NumMatrix {
private:
vector<vector<int> > dp;
public:
    NumMatrix(vector<vector<int>> matrix) {
        int n = matrix.size();
        int m = n ? matrix[0].size():0;
        for(int i = 0; i < n; ++i) {
            dp.push_back(vector<int>(m));
            for(int j = 0; j < m; ++j) {
                if(j==0)    dp[i][j] = matrix[i][j];
                else dp[i][j] = matrix[i][j]+dp[i][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int r = row1; r <= row2; ++r) {
            sum += dp[r][col2];
            if(col1 > 0) sum -= dp[r][col1-1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
