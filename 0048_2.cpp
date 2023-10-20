class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        if(len == 1){
            return;
        }
        int tmp;
        int t = 0, b = len/2, l = 0, r = len-2;
        int i = 0, j = 0;
        for(i = t; i <= b; ++i){
            for(j = l; j <= r; ++j){
                tmp = matrix[i][j];
                matrix[i][j] = matrix[len-1-j][i];
                matrix[len-1-j][i] = matrix[len-1-i][len-1-j];
                matrix[len-1-i][len-1-j] = matrix[j][len-1-i];
                matrix[j][len-1-i] = tmp;
            }
            ++l;
            --r;
        }
        return;

    }
};
