class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int K) {
        int l = nums.size();
        int i  =0, j = 0, k = 0;

        vector<double> sum(l, 0);
        sum[0] = nums[0];
        for(i = 1; i < l; ++i){
            sum[i] = sum[i-1] + nums[i];
        }

        vector<double> dp(l, 0);
        for(i = 0; i < l; ++i){
            dp[i]= sum[i]/(i+1);
        }

        for(k = 2; k <= K; ++k){
            for(i = l-1; i >= k-1; --i){
                for(j = k-2; j < i; ++j){
                    dp[i] = max(dp[i], (sum[i]-sum[j])/(i - j) + dp[j]);
                }
            }
        }
        
        return dp[l-1];
    }
};
