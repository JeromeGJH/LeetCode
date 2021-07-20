class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int l = nums.size();
        vector<int> sum(l, 0);
        vector<vector<int>> dp(l, vector<int>(m + 1, INT_MAX));
        int  i = 0,  j = 0, k = 0;
        sum[0] = nums[0];
        for(i = 1; i < l; ++i){
            sum[i] = sum[i - 1] + nums[i];
        }

        for(i = 0; i < l; ++i){
            dp[i][1] = sum[i];
            for(j = 2; j <= m && j <= i + 1; ++j){
                for(k = j - 2; k < i; ++k){
                    dp[i][j] = min(dp[i][j], max(dp[k][j-1], sum[i] - sum[k]));
                }
            }
        }
        return dp[l-1][m];
    }
};
