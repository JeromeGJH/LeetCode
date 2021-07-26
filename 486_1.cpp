class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int l = nums.size();
        vector<vector<int>> dp(l , vector<int>(l, 0));
        dp[0][0] = nums[0];
        int i , j;
        int min1, min2;
        for(j = 1; j <l; ++j){
            dp[j][j] = nums[j];
            dp[j-1][j] = abs(nums[j-1] - nums[j]);
            for(i = j-2; i >= 0; --i){
                min1 = min(nums[i] - nums[j] + dp[i+1][j-1], nums[i] - nums[i+1] + dp[i+2][j]);
                min2 = min(nums[j] - nums[i] + dp[i+1][j-1], nums[j] - nums[j-1] + dp[i][j-2]);
                dp[i][j] = max(min1, min2);
            }
        }
        return dp[0][l-1] >= 0;
    }
};
