class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int  l1 = text1.length(), l2 = text2.length();
        vector<vector<int>> dp(l1, vector<int>(l2, 0));
        int i = 0, j = 0;
        for(i = 0; i < l1; ++i){
            dp[i][0] = text1[i] == text2[0]?1: i==0?0:dp[i-1][0];
            for(j = 1; j < l2; ++j){
                if(text1[i] == text2[j]){
                    dp[i][j] = i == 0? 1:dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = i == 0? dp[i][j-1]:max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[l1-1][l2-1];
    }
};
