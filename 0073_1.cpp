class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> zeros(row+col, 0);
        
        int i, j;
        for(i = 0; i < row; ++i){
            for(j = 0; j< col; ++j){
                if(matrix[i][j] == 0){
                    zeros[i] = 1;
                    zeros[row+j] = 1;
                }
            }
        }

        for(i = 0; i < row; ++i){
            if(zeros[i] == 1){
                for(j = 0; j < col; ++j){
                    matrix[i][j] = 0;
                }
            }
        }
        for(j = 0; j < col; ++j){
            if(zeros[row+j] == 1){
                for(i = 0; i < row; ++i){
                    matrix[i][j] = 0;
                }
            }
        }
        return;



    }
};
