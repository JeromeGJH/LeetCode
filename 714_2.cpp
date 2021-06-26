class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int l = prices.size();
        int dp00, dp01, dp11, dp10;
        dp00 = 0;
        dp01 = -prices[0];
        for(int i = 1; i < l; ++i){
            dp10 = max(dp00, dp01 + prices[i] - fee);
            dp11 = max(dp01, dp00 - prices[i]);
            dp00 = dp10;
            dp01 = dp11;
        }
        return max(dp00, dp01);
    }
};
