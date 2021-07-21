class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int l = s.length();
        vector<vector<int>> dp(l, vector<int>(l, 0));
        int i = 0, j = 0, ans = 1;
        for(j = 0; j < l; ++j){
            dp[j][j] = 1;
            for(i = j-1; i >= 0; --i){
                if(s[i] == s[j]){
                    dp[i][j] = i+1 ==j?2:dp[i+1][j-1]+2;
                }else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
        

    }
};
