class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> dp(col, 0);
        int i = 0, j = 0;
        int ans = 0;
        int pre1, pre2;
        for(i = 0; i < col; ++i){
            if(matrix[0][i] == '1'){
                dp[i] = 1;
                ans = 1;
            }
        }
        
        for(i = 1; i < row; ++i){
            
            pre1 = dp[0];
            dp[0] = matrix[i][0] == '1'? 1:0;
            ans = max(ans, dp[0]);
            
            for(j = 1; j < col; ++j){
                
                if(matrix[i][j] == '1'){
                    pre2 = dp[j];
                    dp[j] = min(min(pre1, dp[j-1]), dp[j]) + 1;
                    ans = max(ans, dp[j]);
                    pre1 = pre2;
                }else{
                    dp[j] = 0;
                }
            }
        }
        
        return ans * ans;

    }
};
