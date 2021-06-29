class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        if(l1 == 0){
            return l2;
        }
        if(l2 == 0){
            return l1;
        }

        vector<vector<int>> dp(l1, vector<int>(l2, 0));
        if(word1[0] == word2[0]){
            dp[0][0] = 0;
        }else{
            dp[0][0] = 1;
        }
        int i = 0, j = 0;
        for(i = 1; i < l1; ++i){
            if(word1[i] == word2[0]){
                dp[i][0] = i;
            }else{
                dp[i][0] = dp[i-1][0] + 1;
            }
        }
        for(i = 1; i < l2; ++i){
            if(word1[0] == word2[i]){
                dp[0][i] = i;
            }else{
                dp[0][i] = dp[0][i-1] + 1;
            }
        }
        for(i = 1; i < l2; ++i){
            for(j = 1; j < l1; ++j){
                if(word1[j] == word2[i]){
                    dp[j][i] = dp[j-1][i-1];
                }else{
                    dp[j][i] = min(dp[j][i-1], min(dp[j-1][i], dp[j-1][i-1])) + 1;
                }
            }
        }
        // for(i = 0; i < l1; ++i){
        //     for(j = 0; j < l2; ++j){
        //         cout << "i: "<<i << " j: "<<j <<"    "<<dp[i][j]<<endl;
        //     }
        // }
        return dp[l1-1][l2-1];

    }
};
