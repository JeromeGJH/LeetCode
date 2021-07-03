class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int  n = matrix.size();
        vector<vector<int>> dp(n , vector<int>(n, 0));
        int i = 0, j = 0;
        for(i = 0; i < n; ++i){
            dp[0][i] = matrix[0][i];
        }
        for(i = 1; i < n; ++i){
            dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + matrix[i][0];
            for(j = 1; j < n-1; ++j){
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i-1][j+1])) + matrix[i][j];
        
            }
            dp[i][n-1] = min(dp[i-1][n-1], dp[i-1][n-2]) + matrix[i][n-1];
        }
        int ans = INT_MAX;
        for(j = 0; j < n; ++j){
            ans = min(ans, dp[n-1][j]);

        }
        return ans;
    }
};
