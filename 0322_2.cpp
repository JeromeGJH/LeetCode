class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans = -1;
        int i;
        if(amount == 0){
            return 0;
        }
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(i = 1; i <= amount; ++i){
            for(auto e: coins){
                if(i - e < 0 || dp[i-e] == INT_MAX){
                    continue;
                }         
                dp[i] = min(dp[i], dp[i-e]+1);
            }
        }
        return dp[amount] == INT_MAX? -1: dp[amount];
    }
};
