class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        int d = k-1;
        if(k > 2 && n % d != 1){
            return -1;
        }
        int i , j , m, h;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> sum(n+1, 0);
        for(i = 1 ; i <= n; ++i){
            sum[i] = sum[i-1] + stones[i-1];
        }
        for(j = 0; j < n; ++j){
            dp[j][j] = 0;
            for(i = j-1; i >= 0; --i){
                dp[i][j] = INT_MAX;
                for(m = i; m < j; m += d){
                    dp[i][j] = min(dp[i][m] + dp[m+1][j], dp[i][j]);
                }
                if((j-i)%d == 0){
                    dp[i][j] = dp[i][j] + sum[j+1]-sum[i];
                }
            }
        }
        return dp[0][n-1];
    }
};




// class Solution {
// public:
//     int mergeStones(vector<int>& stones, int k) {
//         int n = stones.size();
//         if ((n-1) % (k-1) != 0)
//         {
//             return -1;
//         }

//         // 初始化
//         int d[n+1][n+1];
//         memset(d, 0, sizeof(d));

//         // 计算前缀和，辅助计算区域的成本和, 预留一个0
//         int sums[n+1];
//         memset(sums, 0, sizeof(int)*(n+1));
//         for (int i = 0; i < n; ++i)
//         {
//             sums[i+1] = sums[i] + stones[i];
//         }

//         // 计算
//         for (int len = k; len <= n; ++len)
//         {
//             // 起点
//             for (int i = 1; i <= n - len +1; ++i)
//             {
//                 // 终点
//                 int j = i + len - 1;
//                 // 按照中间点k去计算最小值
//                 d[i][j] = INT_MAX;
//                 for (int x = i; x < j; x += k-1)
//                 {
//                     d[i][j] = min(d[i][j], d[i][x] + d[x+1][j]);
//                 }

//                 // 合并成一堆时候额外成本（就是i,j之间的和）
//                 if ((j-i)%(k-1) == 0)
//                 {
//                     d[i][j] += sums[j] - sums[i-1];
//                 }
//                 // cout << i << "~" << j << " " << d[i][j] << endl;
//             }
//         }

//         return d[1][n];
//     }
// };
