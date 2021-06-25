class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = prices.size(), last_dp = 0, cur_dp, ans = 0;
        for(int i = 1; i < l; ++i){
            int tmp = last_dp - prices[i-1] + prices[i];
            cur_dp = tmp <= 0? 0: tmp;
            ans = max(ans, cur_dp);
            last_dp = cur_dp;
        }
        return ans;
    }
};
