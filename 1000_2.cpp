class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        int d = k-1;
        if(k > 2 && n % d != 1){
            return -1;
        }
        int i , j , m, h;
        vector<vector<vector<long>>> dp(n, vector<vector<long>>(n, vector<long>(k+1, INT_MAX)));
        vector<int> sum(n+1, 0);
        for(i = 1 ; i <= n; ++i){
            sum[i] = sum[i-1] + stones[i-1];
        }
        //cout<<"here1";
        for(j = 0; j < n; ++j){
            dp[j][j][1] = 0;
            for(i = j-1; i >= 0; --i){
                for(h = 2; h <= k; ++h){
                    for(m = i; m < j; ++m){
                        dp[i][j][h] = min(dp[i][m][1] + dp[m+1][j][h-1], dp[i][j][h]);
                    }
                    dp[i][j][1] = dp[i][j][k] + sum[j+1]-sum[i];
                }
                
            }
        }
        return dp[0][n-1][1];
    }
};
