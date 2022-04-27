class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1;
        if(matrix[0][0] > target){
            return false;
        }
        if(matrix[m-1][n-1] < target){
            return false;
        }
        while (x < m && y >= 0) {
            if (matrix[x][y] == target) {
                return true;
            }
            if (matrix[x][y] > target) {
                --y;
            }else{
                ++x;
            }
        }
        return false;
    }
};
