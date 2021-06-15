class Solution {
public:
    int minCut(string s) {
        int l = s.length();
        vector<vector<int>> dp(l, vector<int>(l, 1));

        int i = 0, j = 0;
        for(j = 1; j < l; ++j){
            for(i = j - 1; i >= 0; --i){
                dp[i][j] = (s[i] != s[j] || dp[i+1][j-1] == 0) ? 0: 1;
            }
        }

        vector<int> cut(l, l-1);
        for(j = 0; j < l; ++j){
            if(dp[0][j] == 1){
                cut[j] = 0;
            }else{
                for(i = 0; i < j; ++i){
                    if(dp[i+1][j] == 1)
                        cut[j] = min(cut[j], cut[i] + 1);
                }
            }
        }

        return cut[l-1];
    }
};

