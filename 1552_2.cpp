class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int i = 0, j = 0, k;
        vector<vector<int>> dp(n, vector<int>(m + 1, 0));
        for(i = 1; i < n; ++i){
            dp[i][2] = position[i] - position[0];
            for(j = 3; j <= m; ++j){
                for(k = i - 1; k >= j - 2; --k){
                    dp[i][j] = max(dp[i][j], min(position[i] - position[k], dp[k][j-1]));
                }
            }
        }
        return dp[n-1][m];
    }
};
