class Solution {
public:
    int countSubstrings(string s) {
        int l = s.length();
        vector<vector<int>> dp(l, vector<int>(l, 0));
        int i = 0, j = 0, ans = 0;
        for(j = 0; j < l; ++j){
            dp[j][j] = 1;
            ans += 1;
            for(i =0; i < j; ++i){
                if(s[i] == s[j]){
                    if(i == j -1){
                        ans += 1;
                        dp[i][j] = 1;
                    }else{
                        if(dp[i+1][j-1] == 1){
                            dp[i][j] = 1;
                            ans += 1;
                        }
                    }
                }
            }
        }
        return ans;

    }
};
