class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int l = costs.size();
        vector<vector<int>> dp(l, vector<int>(3, INT_MAX));
        vector<vector<int>> tmp(3, vector<int>(3, 0));
        int i = 0, j = 0;
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];

        for(i = 1; i < l; ++i){
            tmp[0][1] = costs[i-1][0] + costs[i][1];
            tmp[0][2] = costs[i-1][0] + costs[i][2];
            tmp[1][0] = costs[i-1][1] + costs[i][0];
            tmp[1][2] = costs[i-1][1] + costs[i][2];
            tmp[2][0] = costs[i-1][2] + costs[i][0];
            tmp[2][1] = costs[i-1][2] + costs[i][1];
            for(j = 0; j < 3; ++j){
                if(i == 1){
                    dp[i][j] = min(tmp[(j+1)%3][j], tmp[(j+2)%3][j]);
                }else{
                    dp[i][j] = min(dp[i-2][j] + tmp[(j+1)%3][j], min(dp[i-2][j] + tmp[(j+2)%3][j], 
                    min(dp[i-2][(j+1)%3] + tmp[(j+2)%3][j], dp[i-2][(j+2)%3] + tmp[(j+1)%3][j])));
                }
            }
        }
        return min(dp[l-1][0], min(dp[l-1][1], dp[l-1][2]));
    }
};
