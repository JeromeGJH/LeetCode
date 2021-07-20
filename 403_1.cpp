class Solution {
public:
    bool canCross(vector<int>& stones) {
        int l = stones.size();
        if(l == 2 && stones[1] - stones[0] == 1){
            return true;
        }
        vector<set<int>> dp(l, set<int>());
        dp[0].insert(1);
        if(stones[1] - stones[0] == 1){
            dp[1].insert(1);
        }else{
            return false;
        }
        int diff = stones[2] - stones[1];
        if(diff == 1 || diff == 2){
            dp[2].insert(diff);
        }else{
            return false;
        }
        if(l == 3){
            return true;
        }
        int i = 0, j  = 0, k = 0;
        for(i = 3; i< l; ++i){
            for(j = i-1; j >= 0; --j){
                diff = stones[i] - stones[j];
                if(dp[j].empty() || *(--dp[j].end()) +1 < diff){
                    continue;
                }
                for(set<int>::iterator it = dp[j].begin(); it != dp[j].end(); it++){
                    if(*it - 1 <= diff && diff <= *it + 1)
                        dp[i].insert(diff);
                }
            }
        }
        return !dp[l-1].empty();
    }
}; 
