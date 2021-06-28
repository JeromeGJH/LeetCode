class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int l1 = s1.length(), l2 = s2.length();
        int i = 0, j = 0;
        vector<vector<int>> dp(l1, vector<int>(l2 , 0));
        vector<vector<int>> sum(l1, vector<int>(l2 , 0));
        vector<int> sum1(l1, 0);
        vector<int> sum2(l2, 0);
        sum1[0] = 0 + s1[0];
        sum2[0] = 0 + s2[0];
        for( i = 1; i < l1; ++i){
            sum1[i] = sum1[i-1] + s1[i];
        }
        for( i = 1; i < l2; ++i){
            sum2[i] = sum2[i-1] + s2[i];
        }

        int ans = 0;
        if(s1[0] == s2[0]){
            sum[0][0] = 0;
        }else{
            sum[0][0] = s1[0] + s2[0];
        }
        for(i = 1; i < l1; ++i){
            if(s1[i] == s2[0]){
                dp[i][0] = 1;
                sum[i][0] = sum1[i-1];
                ans = 1;
            }
            else{
                dp[i][0] = dp[i-1][0];
                sum[i][0] = sum[i-1][0] + s1[i];
            }

        }
        for(i = 1; i < l2; ++i){
            if(si[0] == s2[i]){
                dp[0][i] = 1;
                sum[0][i] = sum2[i-1];
                ans = 1;
            }
            else{
                dp[0][i] = dp[0][i-1];
                sum[0][i] = sum[0][i-1] + s2[i];
            }

        }
        for(i  = 1; i < l1; ++i){
            for(j = 1; j < l2; ++j){
                if(s1[i] == s2[j]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    sum[i][j] = sum[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    sum[i][j] = min(sum[i-1][j] + s1[i], sum[i][j-1] + s2[j]);
                }

            }
        }
        return sum[l1-1][l2-1];

    }
};
