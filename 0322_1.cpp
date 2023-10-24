class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans = -1;
        int len = coins.size(), i;
        unordered_set<long> coinSet;
        int l = coins[0], r=coins[0];
        for(i = 0; i < len; ++i){
            coinSet.emplace(coins[i]);
            if(l > coins[i]){
                l = coins[i];
            }
            if(r < coins[i]){
                r = coins[i];
            }
        }
        
        if(amount == 0){
            return 0;
        }
        vector<long> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(auto e : coinSet){
            if(e > amount){
                continue;
            }
            dp[e] = 1;
        }
        for(i = 0; i <= amount; ++i){
            if(dp[i] == INT_MAX){
                continue;
            }else{
                for(auto e: coinSet){
                    if(i+e > amount){
                        continue;
                    }
                    dp[i+e] = min(dp[i+e], dp[i]+1);
                }
            }
        }
        if(dp[amount] == INT_MAX){
            return -1;
        }else{
            return dp[amount];
        }
    }
};
