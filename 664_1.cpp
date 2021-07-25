class Solution {
public:
    int strangePrinter(string s) {
        int l = s.length();
        int i = 0, j = 0, k = 0;
        vector<vector<int>> dp(l, vector<int>(l, 0));
        for(j = 0; j < l; ++j){
            dp[j][j] = 1;
            for(i = j-1; i >= 0; --i){
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j];
                }else{
                    dp[i][j] = 1 + dp[i+1][j];
                    for(k = j-1; k > i; --k){
                        if(s[i] == s[k]){
                            dp[i][j] = min(dp[i][j], dp[i+1][k] + dp[k+1][j]);
                        }
                    }
                }
            }
        }
        // for(i = 0; i < l; ++i){
        //     for(j = i; j <l; ++j){
        //         cout<<i << "  "<<j<<"  "<<dp[i][j]<<endl;
        //     }
        // }
        return dp[0][l-1];
    }
};
