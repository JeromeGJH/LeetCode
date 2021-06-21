class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int l = costs.size();
        int k = costs[0].size();

        vector<vector<int>> dp(l , vector<int>(k, INT_MAX));
        int i = 0, j = 0, m = 0;
        int min_id1 = 0, min_id2 = 0;
        int count = 0;
        for(j = 0; j<k; ++j){
            dp[0][j] = costs[0][j];
            if(dp[0][min_id1] > costs[0][j]){
                min_id1 = j;
            }
        }

        int tmp = 0;
        for(i = 1; i < l; ++i){
            for(j = 0; j < k; ++j){
                if(j != min_id1){
                    dp[i][j] = dp[i-1][min_id1] + costs[i][j];
                }else{
                    for(m = 1; m < k; ++m){
                        dp[i][j] = min(dp[i-1][(j+m)%k] + costs[i][j], dp[i][j]);
                    }
                }
                if(dp[i][tmp] > dp[i][j]){
                    tmp = j;
                }
            }
            min_id1 = tmp;
        }
        int ans = INT_MAX;
        for(i = 0; i < k; ++i){
            ans = min(dp[l-1][i], ans);
        }
        return ans;
    }
};
