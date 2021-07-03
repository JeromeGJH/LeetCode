class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0 ));
        int ans = 0;
        dp[m-1][n-1] = matrix[m-1][n-1] - '0';
        if(dp[m-1][n-1] == 1){
            ans = 1;
        }
        int i = 0, j = 0, k = 0;
        
        for(i = 0; i < m; ++i){
            dp[i][n-1] = matrix[i][n-1] - '0';
            if(dp[i][n-1] == 1){
                ans = 1;
            }
        }
        for(i = 0; i < n; ++i){
            dp[m-1][i] = matrix[m-1][i] - '0';
            if(dp[m-1][i] == 1){
                ans = 1;
            }
        }
        
        //cout << "here1";
        for(i = m-2; i >= 0; --i){
            for(j = n-2; j >= 0; --j){
                if(matrix[i][j] == '0'){
                    dp[i][j] = 0;
                }else{
                    for(k = 1; k <= dp[i+1][j+1]; ++k){
                        if(matrix[i+k][j] != '1' || matrix[i][j+k] != '1'){
                            break;
                        }
                    }
                    dp[i][j] = k;
                    ans = max(ans, k);
                }
            }
        }
        return ans*ans;
    }
};
