class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int i = 0, j = 0, k,dist, tmp;
        vector<vector<int>> dp(n, vector<int>(m + 1, 0));
        for(i = 1; i < n; ++i){
            dp[i][2] = position[i] - position[0];
            for(j = 3; j <= m; ++j){
                for(k = i - 1; k >= j - 2; --k){
                    dist = position[i] - position[k];
                    if(dist > dp[k][j-1]){
                        tmp = dp[k][j-1];
                    }else{
                        tmp = dist;
                    }
                    // if(i == 2 && k == 1){
                    //     cout << dist << " " << tmp << endl;
                    // }
                    dp[i][j] = max(dp[i][j], tmp);
                }
            }
        }
        // for(i = 1; i < n; ++i){
            
        //     for(j = 2; j <= m; ++j){
        //         cout << i << " " << j << " " << dp[i][j] << endl;;
        //     }
        // }
        return dp[n-1][m];
    }
};
