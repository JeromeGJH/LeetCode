class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int l = nums.size();
        int i  =0, j = 0, m = 0;

        vector<double> sum(l, 0);
        sum[0] = nums[0];
        for(i = 1; i < l; ++i){
            sum[i] = sum[i-1] + nums[i];
        }

        vector<vector<double>> dp(l, vector<double>(k+1, 0));
        for(i = 0; i< l; ++i){
            dp[i][1] = sum[i]/(i + 1);
            for(j = 2; j<=k && j <= i+1; ++j){
                for(m = j-2; m < i; ++m){
                    dp[i][j] = max(dp[i][j], dp[m][j-1] + (sum[i]-sum[m])/(i-m));
                }
            }
        }
        return dp[l-1][k];
    }
};
