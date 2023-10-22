class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[row-1].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        int i = 0, j = 0;
        dp[0][0] = triangle[0][0];
        for(i = 1; i < row; ++i){
            dp[i][0] = dp[i-1][0] + triangle[i][0];
            for(j = 1; j < i; ++j){
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
            dp[i][i] = dp[i-1][i-1] + triangle[i][i];
        }
        int res = dp[row-1][0];
        for(i = 1; i < row; ++i){
            if(res > dp[row-1][i]){
                res = dp[row-1][i];
            }
            //cout << dp[row-1][i] << endl;
        }
        return res;

    }
};
