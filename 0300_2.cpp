class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int i = 0, j = 0, res = 1;
        for(i = 1; i < n; ++i){
            for(j = 0; j < i; ++j){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
