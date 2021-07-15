class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l = nums.size(), i = 0;
        vector<vector<int>> dp(l , vector<int>(2, 0));
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        int ans = nums[0];
        for(i = 1; i < l; ++i){
            if(nums[i-1] == 0){
                if(nums[i] >= 0){
                    dp[i][0] = nums[i];
                    dp[i][1] = 0;
                }else{
                    dp[i][0] = 0;
                    dp[i][1] = nums[i];
                }
            }else if(dp[i-1][0] <= 0){
                if(nums[i] >= 0){
                    dp[i][0] = nums[i];
                    dp[i][1] = nums[i] * dp[i-1][1];
                    //ans = max(ans, dp[i]);
                }else{
                    dp[i][0] = dp[i-1][1] * nums[i];
                    dp[i][1] = nums[i];
                    //ans =max(ans, dp[i]);
                }
            }else{
                if(nums[i] >= 0){
                    dp[i][0] = nums[i] * dp[i-1][0];
                    dp[i][1] = nums[i] * dp[i-1][1];
                    //ans = max(ans, dp[i]);
                }else{
                    dp[i][0] = dp[i-1][1] * nums[i];
                    dp[i][1] = dp[i-1][0] * nums[i];
                    //ans =max(ans, dp[i]);
                }

            }
            ans =max(ans, dp[i][0]);
        }
        
        return ans;
    }
};
