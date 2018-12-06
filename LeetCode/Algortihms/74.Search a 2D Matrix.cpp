/*
Write an efficient algorithm that searches for a value in an m x n matrix, return the occurrence of it.

This matrix has the following properties:

Integers in each row are sorted from left to right.
Integers in each column are sorted from up to bottom.
No duplicate integers in each row or column.
*/

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        if(m == 0) return 0;
        int i = 0, j = m-1, count = 0;
        cout << n << ' '<< m << endl;
        while(i < n && j >= 0) {
            cout << i << ' ' << j << endl;
            if(matrix[i][j] < target) ++i;
            else {
                if(matrix[i][j] == target)  ++count;
                --j;
            }
        }
        return count;
    }
};
