class Solution {
public:
    int calcF(int K, int T, unordered_map<int, int>& dp){
        if( T == 1 || K == 1){
            dp[K * 1000 + T] = T + 1;
            return T + 1;
        }else{
            if(dp.count((K - 1) * 1000 + T - 1) != 1){
                dp[(K - 1) * 1000 + T - 1] = calcF(K-1, T-1, dp);
            }
            if(dp.count(K * 1000 + T - 1) != 1){
                dp[K * 1000 + T - 1] = calcF(K-1, T-1, dp);
            }
            return dp[(K - 1) * 1000 + T - 1] + dp[K * 1000 + T - 1];
        }
    
    }
    int superEggDrop(int K, int N) {
        unordered_map<int, int> dp;
        int T = 1;
        while(1){
            dp[K * 1000 + T]  = calcF(K, T, dp);
            if(dp[K * 1000 + T] < N+1)
                T++;
            else
                break;
        }
        return T;

    }
};
