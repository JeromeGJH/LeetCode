class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int l = values.size();
        vector<vector<int>> dp(l, vector<int>(l, 0));
        int i , j , k;
        for(j  =0; j <l; ++j){
            for(i = j-2; i >= 0; --i){
                dp[i][j] = values[i+1]*values[i]*values[j] + dp[i+1][j];
                for(k = i+2; k < j; ++k){
                    dp[i][j] = min(dp[i][j], values[k]*values[i]*values[j] + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][l-1];
    }
};
