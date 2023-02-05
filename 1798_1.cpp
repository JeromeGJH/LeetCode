class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());

        int r = 1;
        for(auto&& coin : coins) {
            if(coin > r) { break; }
            r += coin;
        }
        return r;
    }
};
