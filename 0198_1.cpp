class Solution {
public:
    int rob(vector<int>& nums) {
        int sum1 = 0, sum2 = 0;
        int len = nums.size();
        if(len == 1){
            return nums[0];
        }
        int i = 0;
        vector<int> dp(len, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(i = 2; i < len; ++i){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[len-1];

    }
};
