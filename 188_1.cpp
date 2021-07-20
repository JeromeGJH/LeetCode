class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int l  = prices.size();
        if( k == 0 || l == 0){
            return 0;
        }
        vector<int> sell(k , 0);
        vector<int> buy(k, 0);
        for(int i = 0; i < k; ++i){
            buy[i] = -prices[0];
        }
        for(int i = 1; i < l; ++i){
            for(int j = 0; j < k; ++j){
                if(j == 0){
                    buy[j] = max(buy[j], -prices[i]);
                    sell[j] = max(sell[j], prices[i] + buy[j]);
                }else{
                    buy[j] = max(buy[j], sell[j-1] - prices[i]);
                    sell[j] = max(sell[j], prices[i] + buy[j]);
                }
            }
        }
        return sell[k-1];
    }
};
