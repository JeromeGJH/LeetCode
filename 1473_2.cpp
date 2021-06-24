class Solution {
public:
    vector<int> findMin(map<int, int>& mp){
        vector<int> ans(2, -1);
        int min1 = INT_MAX, min2 = INT_MAX;
        for(map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it){
            if(min1 > it->second){
                ans[1] = ans[0];
                ans[0] = it->first;
                min2 = min1;
                min1 = it->second;
            }else{
                if(min1 <= it->second && it->second < min2){
                    min2 = it->second;
                    ans[1] = it->first;
                }
            }
        }
        return ans;
    }

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int  i =  0, j = 0, k = 0;
        int res;
        vector<vector<map<int, int>>> dp(m, vector<map<int, int>>(target + 1, map<int, int>()));
        vector<vector<vector<int>>> min_index(m, vector<vector<int>>(target + 1, vector<int>(2, -1)));
        if(houses[0] > 0){
            dp[0][1][houses[0]-1] = 0;
        }else{
            for(j = 0; j < n; ++j ){
                dp[0][1][j] = cost[0][j];
            }
        }

        for(i = 1; i < m; ++i){
            if(!dp[i-1][1].empty()){
                if(houses[i] == 0)
                    for(map<int, int>::iterator it = dp[i-1][1].begin(); it != dp[i-1][1].end(); ++it)
                        dp[i][1][it->first] = dp[i-1][1][it->first] + cost[i][it->first];
                else
                    if(dp[i-1][1].count(houses[i]-1))
                        dp[i][1][houses[i]-1] = dp[i-1][1][houses[i]-1];
                   
            }
            for(j = 2; j <= target && j <= i+1; ++j){
                if(!dp[i-1][j].empty()){
                    if(houses[i] == 0){
                        for(map<int, int>::iterator it = dp[i-1][j].begin(); it != dp[i-1][j].end(); ++it)
                            dp[i][j][it->first] = dp[i-1][j][it->first] + cost[i][it->first];
                    }else{
                        if(dp[i-1][j].count(houses[i]-1))
                            dp[i][j][houses[i]-1] = dp[i-1][j][houses[i]-1];
                    }    
                }
                if(!dp[i-1][j-1].empty()){
                    vector<int> tmp = findMin(dp[i-1][j-1]);
                    if(houses[i] == 0){
                        for(k = 0; k < n; ++k){
                            if(k != tmp[0]){
                                dp[i][j][k] = dp[i][j].count(k) == 0? dp[i-1][j-1][tmp[0]] + cost[i][k]:
                                min(dp[i-1][j-1][tmp[0]] + cost[i][k], dp[i][j][k]);
                            }else{
                                if(tmp[1] != -1)
                                    dp[i][j][k] = dp[i][j].count(k) == 0?dp[i-1][j-1][tmp[1]] + cost[i][k]:
                                    min(dp[i-1][j-1][tmp[1]] + cost[i][k], dp[i][j][k]);
                            }
                        }
                    }else{
                        if(houses[i] - 1 != tmp[0]){
                            dp[i][j][houses[i]-1] = dp[i][j].count(houses[i]-1) == 0?dp[i-1][j-1][tmp[0]]:
                            min(dp[i-1][j-1][tmp[0]], dp[i][j][houses[i]-1]);
                        }else{
                            if(tmp[1] != -1)
                                dp[i][j][houses[i]-1] = dp[i][j].count(houses[i]-1) == 0?dp[i-1][j-1][tmp[1]]:
                                min(dp[i-1][j-1][tmp[1]], dp[i][j][houses[i]-1]);              
                        }
                    }    
                }
            }
        }
        min_index[m-1][target] = findMin(dp[m-1][target]);
        if(min_index[m-1][target][0] == -1){
            return -1;
        }else{
            return dp[m-1][target][min_index[m-1][target][0]];
        }
    }
};
