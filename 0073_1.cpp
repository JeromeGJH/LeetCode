class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int, bool> zeros;
        int row = matrix.size();
        int col = matrix[0].size();
        int i, j;
        for(i = 0; i < row; ++i){
            for(j = 0; j< col; ++j){
                if(matrix[i][j] == 0){
                    zeros[i] = true;
                    zeros[row+j] = true;
                }
            }
        }

        for(i = 0; i < row; ++i){
            if(zeros.count(i) == 1){
                for(j = 0; j < col; ++j){
                    matrix[i][j] = 0;
                }
            }
        }
        for(j = 0; j < col; ++j){
            if(zeros.count(j+row) == 1){
                for(i = 0; i < row; ++i){
                    matrix[i][j] = 0;
                }
            }
        }
        return;



    }
};
