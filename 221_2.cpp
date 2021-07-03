class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0 ));
        int i = 0, j = 0, k = 0, ans = 0;
        for(i = m-1; i >= 0; --i){
            for(j = n-1; j >= 0; --j){
                dp[i][j] = matrix[i][j] - '0';
                if(dp[i][j] != 0){
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
