class Solution {
public:
    bool isScramble(string s1, string s2) {
        int l1 = s1.length(), l2 =s2.length();
        int i = 0, j = 0, len = 0, k = 0;
        vector<vector<vector<bool>>> dp(l1, vector<vector<bool>>(l1, vector<bool>(l1, false)));
        for(i = 0; i < l1; ++i){
            for(j = 0; j < l1; ++j){
                if(s1[i] == s2[j]){
                    dp[i][j][0] = true;

                }
            }
        }
        for(len = 1; len <= l1-1; ++len){
            for(i = 0; i + len < l1; ++i){
                for(j = 0; j + len < l1; ++j){
                    for(k = 0; k <= len-1; ++k){
                        bool a = dp[i][j][k] && dp[i+k+1][j+k+1][len - k - 1];
                        bool b = dp[i][j+len - k][k] && dp[i+k+1][j][len - k - 1];
                        if(a || b){
                            dp[i][j][len] = true;
                        }
                    }
                }
            }
        }
        return dp[0][0][l1-1];

    }
};
