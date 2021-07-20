class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int l = costs.size();
        int k = costs[0].size();

        vector<vector<int>> dp(l , vector<int>(k, INT_MAX));
        int i = 0, j = 0, m = 0;
        for(j = 0; j<k; ++j){
            dp[0][j] = costs[0][j];
        }
        for(i = 1; i < l; ++i){
            for(j = 0; j < k; ++j){
                for(m = 1; m < k; ++m){
                    dp[i][j] = min(dp[i-1][(j+m)%k] + costs[i][j], dp[i][j]);
                }
            }
        }
        int ans = INT_MAX;
        for(i = 0; i < k; ++i){
            ans = min(dp[l-1][i], ans);
        }
        return ans;

    }
};
