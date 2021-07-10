class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int l = nums.size();
        int i = 0, j = 0;
        vector<int> dp(l , 0);
        dp[0] = nums[0];
        for( i= 1; i <l;++i){
            dp[i] = dp[i-1] + nums[i];
            //cout << dp[i];
        }
        int ans = 0;
        for( i = l-1; i >= 0; --i){
            if(dp[i] == k){
                ans = max(ans, i+1);
            }
            for(j = 0; j < i; ++j){
                if(dp[i]-dp[j] == k){
                    ans = max(ans, i - j);
                }
            }
        }
        return ans;

    }
};
