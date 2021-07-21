class Solution {
public:
    string longestPalindrome(string s) {
        int l = s.length();
        vector<vector<int>> dp(l, vector<int>(l, 0));
        int i  =0, j  =0, ans = 1, res[2] = {0};
        for(j = 0; j < l; ++j){
            dp[j][j] = 1;
            for(i = 0; i < j; ++i){
                if(s[i] == s[j]){
                    if(i + 1 == j){
                        dp[i][j] = 1;
                        if(ans < j - i + 1){
                            ans = j - i + 1;
                            res[0] = i;
                            res[1] = j;
                        }
                    }else{
                        if(dp[i+1][j-1] == 1){
                            dp[i][j] = 1;
                            if(ans < j - i + 1){
                                ans = j - i + 1;
                                res[0] = i;
                                res[1] = j;
                            }
                        }
                    }
                }
            }
        }
        return s.substr(res[0], res[1]-res[0]+1);

    }
};
