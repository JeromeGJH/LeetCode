class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = prices.size();
        int i = 0, ans = 0;
        for(i = 1; i < l; ++i){
            if(prices[i] - prices[i-1] > 0){
                ans += prices[i] - prices[i-1];
            }
        }
        return ans;
    }
};
