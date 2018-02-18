class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int, int> > v;
        vector<int> rows(9,0);
        vector<int> columns(9,0);
        vector<int> boxes(9,0);
        Find_emptyCells(board, v, rows, columns, boxes);
        cout<<Find_Soln(board, v, 0, rows, columns, boxes);
    }

    void Find_emptyCells(vector<vector<char>>& board, vector<pair<int,int> >& v, vector<int>& rows, vector<int>& columns, vector<int>& boxes){
        for(int r=0;r<9; r++){
            for(int c=0;c<9; c++){
                if(board[r][c]=='.')    v.push_back(make_pair(r,c));
                else{
                    int idx=board[r][c]-'1';
                    rows[r] |=(1<<idx);
                    columns[c] |=(1<<idx);
                    boxes[(r/3)*3+(c/3)] |=(1<<idx);
                }
            }
        }
    }

    bool Find_Soln(vector<vector<char>>& board, vector<pair<int,int> >& v, int idx, vector<int>& rows, vector<int>& columns, vector<int>& boxes){
        if(idx==v.size())   return true;
        for(int i=1;i<=9;i++){
            int r=v[idx].first, c=v[idx].second;
            board[r][c]='0'+i;
            if(IsSafe(board, r, c, rows, columns, boxes)){
                if(Find_Soln(board, v, idx+1, rows, columns, boxes))
                    return true;
                unSet(board, r, c, rows, columns, boxes);
            }
            board[r][c]='.';
        }
        return false;
    }

    bool IsSafe(vector<vector<char>>& board, int r, int c, vector<int>& rows, vector<int>& columns, vector<int>& boxes){
        int val=board[r][c]-'1';
        int check=(1<<val);
        if(check & rows[r]) return false;
        if(check & columns[c])  return false;
        if(check & boxes[(r/3)*3+(c/3)])    return false;

        rows[r] |= check;     columns[c] |= check;  boxes[(r/3)*3+(c/3)] |= check;
        return true;
    }

    void unSet(vector<vector<char>>& board, int r, int c, vector<int>& rows, vector<int>& columns, vector<int>& boxes){
        int val=board[r][c]-'1';
        int check= ~(1<<val);
        rows[r] &= check;     columns[c] &= check;  boxes[(r/3)*3+(c/3)] &= check;
    }
};
