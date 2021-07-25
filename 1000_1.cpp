class Solution {
public:
    int calSum(vector<int>& stones, int k, int n){
        int i = 0, j = 0;
        int minv = INT_MAX, msum;
        vector<int> sum(n+1, 0);
        for(i = 1; i <= n; ++i){
            sum[i] = sum[i-1] + stones[i-1];
        }
        if( n == k){
            return sum[n];
        }
        for(i = n-1; i >= k-1; --i){
            vector<int> s(n-k+1, 0);
            msum = sum[i+1]-sum[i-k+1];
            for(j = 0; j <= i-k; ++j){
                s[j] = stones[j];
            }
            s[j] = msum;
            for(j = i-k+2; j <= n-k; ++j){
                s[j] = stones[j + k-1];
            }
            minv = min(minv, calSum(s, k, n-k+1) + msum);
        }
        return minv;
    }
    
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        int d = k-1;
        if(n == 1){
            return 0;
        }
        if(k > 2 && n % d != 1){
            return -1;
        }
        if(k > n){
            return -1;
        }
        // int i , j , m;
        // vector<vector<int>> dp(n, vector<int>(n, 0));
        // vector<int> sum(n+1, 0);
        // for(i = 1 ; i <= n; ++i){
        //     sum[i] = sum[i-1] + stones[i-1];
        // }
        // for(j = k - 1; j < n; ++j){
        //     dp[j-d][j] = sum[j+1] - sum[j-d];
        //     for(i = j - d - d; i >= 0; i -= d){
        //         dp[i][j] = sum[j+1] - sum[i] + dp

        //     }
        // }
        return calSum(stones, k, n);


    }
};
