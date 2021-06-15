class Solution {
public:
    int minCut(string s) {
        int l = s.length();
        if( l == 1){
            return 0;
        }
        vector<vector<int>> dp(l, vector<int>(l, l-1));
   
        int i = 0, j = 0, k = 0;
        dp[0][0] = 0;
        for(j = 1; j < l; ++j){
            dp[j][j] = 0;
            if(s[j] == s[j-1])
                dp[j-1][j] = 0;
            else
                dp[j-1][j] = 1;
            for(i = j - 2; i >= 0; --i){
                if(s[i] == s[j] && dp[i+1][j-1] == 0){
                    dp[i][j] = 0;
                }else{
                    for(k=i; k<j; ++k){
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + 1);
                    }
                }
            }
        }

        return dp[0][l-1];
    }
};
