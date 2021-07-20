class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = prices.size();
        vector<int> profit1(l, 0);
        vector<int> profit2(l, 0);
        //profit[0][0] = 0;
        int  i = 0,  tmp;
        int last =0, cur = 0, ans = 0;
        for(i = 1; i < l; ++i){
            tmp = last - prices[i-1] + prices[i];
            cur = tmp > 0? tmp:0;
            ans = max(cur, ans);
            profit1[i] = ans;
            last = cur;
        }
        last =0; cur = 0; ans = 0;
        int res;
        for(i = l-2; i >= 0;--i){
            tmp = last + prices[i+1] - prices[i];
            cur = tmp > 0? tmp:0;
            ans = max(cur, ans);
            res = max(ans + profit1[i], res);
            last = cur;
        }
        return res;

    }
};
