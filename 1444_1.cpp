
const int mod = 1e9 + 7;
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        const int m = pizza.size();
        const int n = pizza[0].length();
        int helpSumVec[m][n];
        memset(helpSumVec, 0, sizeof(helpSumVec));
        // 构建二维前缀和数组
        if(pizza[m - 1][n - 1] == 'A') helpSumVec[m - 1][n -1] = 1;
        for(int i = m - 2; i >= 0; i--) helpSumVec[i][n - 1] = helpSumVec[i + 1][n - 1] + ((pizza[i][n - 1] == 'A')?1:0);
        for(int i = n - 2; i >= 0; i--) helpSumVec[m - 1][i] = helpSumVec[m - 1][i + 1] + ((pizza[m - 1][i] == 'A')?1:0);
        for(int i = m - 2; i >= 0; i--)
        {
            for(int j = n - 2; j >= 0; j--)
            {
                helpSumVec[i][j] = ((pizza[i][j] == 'A')?1:0) + helpSumVec[i][j + 1] +
                helpSumVec[i + 1][j] - helpSumVec[i + 1][j + 1];
            }
        }
        if(helpSumVec[0][0] < k) return 0;
        if(k == 1) return 1;
        const int numK = k;
        int dp[m][n][numK];
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        int res = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int x = 1; x < k; x++)
                {
                    if(helpSumVec[i][j] < (k - x)) continue;
                    else
                    {
                        // 水平
                        for(int a = 0; a < i; a++)
                        {
                            if((helpSumVec[a][j] - helpSumVec[i][j])  >= 1) 
                                dp[i][j][x] = (dp[i][j][x] + dp[a][j][x - 1]) % mod;
                        }
                        // 垂直
                        for(int a = 0; a < j; a++)
                        {
                            if((helpSumVec[i][a] - helpSumVec[i][j]) >= 1) 
                                dp[i][j][x] =  (dp[i][j][x] + dp[i][a][x - 1]) % mod;
                        } 
                    }
                }
                res = ((res % mod) + (dp[i][j][k - 1] % mod)) % mod;
            }
        }
        return res;
    }
};
