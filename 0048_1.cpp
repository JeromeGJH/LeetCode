class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        if(len == 1){
            return;
        }
        vector<vector<int>> tmp(matrix.begin(), matrix.end());
        int i = 0, j = 0, m = len-1, n = 0;
        while(j < len){
            i = 0;
            n = 0;
            while(i < len){
                matrix[i][j]=tmp[m][n];
                ++i;
                ++n;

            }
            ++j;
            --m;
        }
        return;

    }
};
