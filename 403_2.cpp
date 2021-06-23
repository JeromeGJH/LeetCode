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
        for(i = 1; i < l; ++i){
            if(dp[i].empty())
                continue;
            for(j = i+1; j<l;++j){
                diff = stones[j] - stones[i];
                if(diff > *(--dp[i].end())+1)
                    break;
                else{
                    for(set<int>::iterator it = dp[i].begin(); it != dp[i].end(); it++){
                        if(*it - 1 <= diff && diff <= *it + 1){
                            dp[j].insert(diff);
                            break;
                        }
                    }     
                }
            }
        }
        // for(i = 0; i < l; ++i){
        //     cout << "i: "<< i <<" ";
        //     for(set<int>::iterator it = dp[i].begin(); it != dp[i].end(); it++){
        //         cout << *it << " ";        
        //     }
        //     cout << endl;
        // }
        return !dp[l-1].empty();
    }
};
