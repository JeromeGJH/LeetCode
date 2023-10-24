class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        int i = 0, j;
        int ans = 1;
        vector<int> dp(len, 1);
        for(i = 1; i < len; ++i){
            for(j = 0; j < i; ++j){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;


    }
};
