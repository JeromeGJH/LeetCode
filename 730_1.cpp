class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int l = s.length();
        vector<vector<vector<long>>> dp(l, vector<vector<long>>(l, vector<long>(4, 0)));
        int i = 0, j = 0, k = 0;
        int mod = pow(10, 9) + 7;
        for(j = 0; j < l; ++j){
            dp[j][j][s[j]-'a'] = 1;
            for(i = j-1; i >= 0; --i){
                if(s[i] == s[j]){
                    for(k = 0; k < 4; ++k){
                        if(s[i] != 'a' + k){
                            dp[i][j][k] = dp[i+1][j-1][k];
                        }else{
                            dp[i][j][k] = (2 + dp[i+1][j-1][0] + dp[i+1][j-1][1]+ dp[i+1][j-1][2]+dp[i+1][j-1][3])%mod;
                        }
                    }
                }else{
                    for(k = 0; k < 4; ++k){
                        if(s[i] != 'a' + k){
                            dp[i][j][k] = dp[i+1][j][k];
                        }
                        if(s[j] != 'a' + k){
                            dp[i][j][k] = dp[i][j-1][k];
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(k = 0; k <4; ++k){
            ans += dp[0][l-1][k];
            ans %= mod;
        }
        return ans;

    }
};
