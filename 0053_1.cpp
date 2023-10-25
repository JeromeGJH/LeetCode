class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, 0);
        dp[0] = nums[0];
        int i  = 0;
        int ans = dp[0];
        for(i = 1; i < len; ++i){
            dp[i] = max(0, dp[i-1]) + nums[i];
            ans = max(ans, dp[i]);
        }
        return ans;

    }
};
