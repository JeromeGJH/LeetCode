class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int l = triangle.size();
        int i = 0, j = 0;
        vector<vector<int>> dp(l, vector<int>(l, INT_MAX));
        dp[0][0] = triangle[0][0];
        int ans = INT_MAX;

        for(i = 1; i < l; ++i){
            dp[i][0] = triangle[i][0] + dp[i-1][0];
            for(j = 1; j <= i; ++j){
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }
        for(j = 0; j < l; ++j){
            ans = min(dp[l-1][j], ans);
        }
        return ans;
    }
};
