class Solution {
public:
    int minInsertions(string s) {
        int l = s.length();
        vector<vector<int>> dp(l, vector<int>(l, 0));
        int i = 0, j = 0;
        for(j = 0; j < l; ++j){
            for(i = j-1; i >= 0; --i){
                if(s[i] == s[j]){
                    if(j != i+1){
                        dp[i][j] = dp[i+1][j-1];
                    }
                }else{
                    dp[i][j] = min(dp[i+1][j] + 1, dp[i][j-1] + 1);
                }
            }
        }
        return dp[0][l-1];
    }
};
