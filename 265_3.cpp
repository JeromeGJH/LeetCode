class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int l = costs.size();
        int k = costs[0].size();

        vector<vector<int>> dp(l , vector<int>(k, INT_MAX));
        int i = 0, j = 0, m = 0;
        int min1 = INT_MAX, min2 = INT_MAX, min_id = 0;
        for(j = 0; j<k; ++j){
            dp[0][j] = costs[0][j];
            if(min1 > dp[0][j]){
                min_id = j;
                min2 = min1;
                min1 = dp[0][j];
            }else if(min2 > dp[0][j])
                min2 = dp[0][j];
        }

        for(i = 1; i < l; ++i){
            int tmp1 =INT_MAX, tmp2 = INT_MAX, tmp_id = 0;
            for(j = 0; j < k; ++j){
                //cout <<"i: " <<i <<" j: "<<j << endl;
                //cout << min2 << endl;
                if(j != min_id){
                    dp[i][j] = min1 + costs[i][j];
                }else{
                    dp[i][j] = min2 + costs[i][j];
                }
                if(tmp1 > dp[i][j]){
                    tmp2 = tmp1;
                    tmp1 = dp[i][j];
                    tmp_id = j;
                }else if(tmp2 > dp[i][j])
                    tmp2 = dp[i][j];
            }
            min_id = tmp_id;
            min1 = tmp1;
            min2 = tmp2;
        }
        
        return min1;
    }
};
