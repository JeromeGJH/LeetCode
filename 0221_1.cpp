class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        int i = 0, j = 0;
        int ans = 0;
        for(i = 0; i < col; ++i){
            if(matrix[0][i] == '1'){
                dp[0][i] = 1;
                ans = 1;
            }
        }
        for(i = 1; i < row; ++i){
            dp[i][0] = matrix[i][0] == '1'? 1:0;
            ans = max(ans, dp[i][0]);
            for(j = 1; j < col; ++j){
                if(matrix[i][j] == '1'){
                    dp[i][j] = min(min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]) + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans * ans;

    }
};
