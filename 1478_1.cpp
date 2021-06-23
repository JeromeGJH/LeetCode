class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        int l  = houses.size();
        if(l == 1)
            return 0;
        sort(houses.begin(), houses.end());
        vector<vector<int>> dp(l , vector<int>(k+1, INT_MAX));
        vector<vector<int>> dis(l , vector<int>(l, 0));
        int i = 0, j = 0, diff = 0, m = 0;
        for( i = 0; i < l; ++i){
            dis[i][i] = 0;
            for(j = i+1; j < l; ++j){
                diff = j - i + 1;
                // cout << diff<< endl;
                dis[i][j] = dis[i][j-1] + houses[j] - (diff % 2 == 1? houses[i + diff/2]:houses[i + diff/2 - 1]);
                    //cout << "i: "<<i << " j: "<<j<< " "<<dis[i][j]<<endl;
                //cout << "i: "<<i << " j: "<<j<< " "<<dis[i][j]<<endl;
            }
        }
        
        for(i = 0; i < l; ++i){
            dp[i][1] = dis[0][i];
            for(j = 2; j <= k && j <= i+1; ++j ){
                for(m = j-2; m < i; ++m){
                    dp[i][j] = min(dp[i][j], dp[m][j-1] + dis[m+1][i]);
                }
            }
        }
        return dp[l-1][k];
    }
};
