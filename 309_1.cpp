class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = prices.size();
        int i = 0, j = 0;
        int ans = 0;
        vector<vector<int>> dp(l, vector<int>(2, 0));

        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        if(l == 1)
            return 0;
        dp[1][0] = max(dp[0][0], dp[0][1] + prices[1]);
        dp[1][1] = max(dp[0][0] - prices[1], dp[0][1]);
        if(l == 2){
            return max(dp[1][0], dp[1][1]);
        }
        
        dp[2][0] = max(dp[1][0], dp[1][1] + prices[2]);
        dp[2][1] = max(dp[0][0] - prices[2], dp[1][1]);
        if(l == 3){
            return max(dp[2][0], dp[2][1]);
        }
        for(i = 3; i < l; ++i){
            dp[i][0] = max(dp[i-1][1] + prices[i], dp[i-1][0]);
            dp[i][1] = max(dp[i-2][0] - prices[i], dp[i-1][1]);
        }
        // for(i = 0; i < l; ++i){
        //     cout<<"i: "<<i << "   "<< dp[i][0]<<"  "<<dp[i][1]<<endl;
        // }
        return max(dp[l-1][0], dp[l-1][1]);
        


    }
};
