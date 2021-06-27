class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int  l1 = text1.length(), l2 = text2.length();
        vector<vector<int>> dp(l1, vector<int>(l2, 0));
        if(text1[0] == text2[0]){
            dp[0][0] = 1;
        }
        int i = 0, j = 0;
        for(i = 1; i < l2; ++i){
            if(text1[0] == text2[i])
                dp[0][i] = 1;
            else
                dp[0][i] = dp[0][i-1];
        }
        //cout << "here2";
        for(i = 1; i < l1; ++i){
            if(text1[i] == text2[0])
                dp[i][0] = 1;
            else
                dp[i][0] = dp[i-1][0];
        }
        //cout << "here1";
        for(i = 1; i < l1; ++i){
            for(j = 1; j < l2; ++j){
                if(text1[i] == text2[j]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        // cout << dp[0][0];
        // cout << dp[2][1];
        // cout << dp[1][0];
        return dp[l1-1][l2-1];
        

    }
};
