class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size()!=9 || board[0].size()!=9)   return false;
        int len=board[0].size();

        //rows check
        for(int r=0;r<len;r++){
            if(board[r].size()!=len)    return false;
            int x=0;
            for(int c=0;c<len;c++){
                if(board[r][c]!='.'){
                    int idx=board[r][c]-'1';
                    if(1<<idx & x)  return false;
                    x|=1<<idx;
                }
            }
        }

        //columns check
        for(int c=0;c<len;c++){
            int x=0;
            for(int r=0;r<len;r++){
                if(board[r][c]!='.'){
                    int idx=board[r][c]-'1';
                    if(1<<idx & x)  return false;
                    x|=1<<idx;
                }
            }
        }

        //Boxes Check
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                int x=0;
                for(int r=i;r<i+3; r++){
                    for(int c=j;c<j+3;c++){
                        if(board[r][c]!='.'){
                            int idx=board[r][c]-'1';
                            if(1<<idx & x)  return false;
                            x|=1<<idx;
                        }
                    }
                }
            }
        }

        return true;
    }
};
