class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int l = nums.size();
        int i  =0, j = 0, m = 0;
        int sum = 0;
        vector<vector<double>> dp(l, vector<double>(k+1, 0));
        for(i = 0; i< l; ++i){
            sum += nums[i];
            dp[i][1] = sum/(i + 1.0);
            for(j = 2; j<=k && j <= i+1; ++j){
                for(m = j-2; m < i; ++m){
                    dp[i][j] = max(dp[i][j], dp[m][j-1] + average(nums, m+1, i));
                }
            }
        }
        return dp[l-1][k];
    }

    double average(vector<int>& nums, int i, int j){
        int sum = 0, k = 0;
        for(k = i; k <= j; ++k){
            sum += nums[k];
        }
        return sum/(j - i + 1.0);
    }
};
