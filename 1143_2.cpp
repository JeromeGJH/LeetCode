class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int  l1 = text1.length(), l2 = text2.length();
        vector<vector<int>> dp(l1, vector<int>(l2, 0));
        if(text1[0] == text2[0]){
            dp[0][0] = 1;
        }
        int i = 0, j = 0;
        
        for(i = 0; i < l1; ++i){
            if(i == 0){
                for(j = 0; j < l2; ++j){
                    if(text1[i] == text2[j]){
                        dp[i][j] = 1;
                    }else{
                        dp[i][j] = j==0?0:dp[i][j-1];
                    }
                }

            }else{
                for(j = 0; j < l2; ++j){
                    if(text1[i] == text2[j]){
                        dp[i][j] = j==0?1:dp[i-1][j-1] + 1;
                    }else{
                        dp[i][j] = j==0?dp[i-1][j]:max(dp[i-1][j], dp[i][j-1]);
                    }
                }

            }
        }
        return dp[l1-1][l2-1];
        

    }
};
