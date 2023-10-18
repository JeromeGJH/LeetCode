class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len < 1){
            return 0;
        }
        int i = 0,pre = prices[0],profit = 0;
        for(i = 1; i < len; ++i){
            if(prices[i] > pre){
                profit += prices[i] - pre;
            }
            pre = prices[i];
        }
        
        return profit;

    }
};
