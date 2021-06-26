class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int l = prices.size();
        int i = 0, ans = 0;
        vector<vector<int>> dp(l, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(i = 1; i < l; ++i){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        // for(i = 0; i < l; ++i){
        //     cout<<"i: "<<i << "   "<< dp[i][0]<<"  "<<dp[i][1]<<endl;
        // }
        
        return max(dp[l-1][0], dp[l-1][1]);
    }
};
