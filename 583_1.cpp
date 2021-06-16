class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        vector<vector<int>> dp(l1, vector<int>(l2, 0));
        int  i = 0, j =0;
        for(i = 0; i < l1; ++i){
            for(j = 0; j< l2; ++j){
                if(word1[i] == word2[j]){
                    if(i == 0 || j == 0){
                        dp[i][j] = 1;
                    }else{
                        dp[i][j] = dp[i-1][j-1] + 1;

                    }
                }else{
                    if(i == 0){
                        if(j == 0){
                            dp[i][j] = 0;
                        }else{
                            dp[i][j] = dp[i][j-1];
                        }
                    }else{
                        if(j == 0){
                            dp[i][j] = dp[i-1][j];
                        }else{
                            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                        }
                    }
                }
            }
        }
        cout << dp[l1-1][l2-1];
        return l1 + l2 - 2 * dp[l1-1][l2-1];

    }
};
