class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        dp[0][0] = 1 - obstacleGrid[0][0];
        int i = 0, j = 0;
        for(i = 1; i < col; ++i){
            if(obstacleGrid[0][i] == 1){
                dp[0][i] = 0;
                continue;
            }
            dp[0][i] = dp[0][i-1];
        }
        for(i = 1; i < row; ++i){
            dp[i][0] = obstacleGrid[i][0] == 1? 0: dp[i-1][0];
            
            for(j = 1; j < col; ++j){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[row-1][col-1];


    }
};
