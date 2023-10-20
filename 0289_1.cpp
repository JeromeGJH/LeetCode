class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();
        int i, j;
        int m, n;
        int l,r,t,b;
        int cnt = 0;
        vector<int> mark(row * col, 0);
        for(i = 0; i < row; ++i){
            for(j = 0; j < col; ++j){
                l = max(0, j-1);
                r = min(col-1, j+1);
                t = max(0, i-1);
                b = min(i+1, row-1);
                cnt = 0;
                for(m = t; m <= b; ++m){
                    for(n = l; n <= r; ++n){
                        if(m != i || n != j){
                            if(board[m][n] == 1){
                                cnt += 1;
                            }
                        }
                    }
                }
                if(board[i][j] == 0){
                    if(cnt == 3){
                        mark[col * i + j] = 1;
                    }
                }else{
                    if(cnt < 2 || cnt > 3){
                        mark[col * i + j] = 1;
                    }
                }
            }
        }
        for(i = 0; i < mark.size(); ++i){
            if(mark[i] == 1){
                board[i/col][i%col] = 1 - board[i/col][i%col];
            }
        }
        return;


    }
};
