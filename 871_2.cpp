class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int num = stations.size();
        vector<long> dp(num+1, 0);
        dp[0] = startFuel;
        int i = 0, j = 0;

        for(i = 0; i < num; ++i){
            for(j = i; j >= 0; --j){
                if(dp[j] >= stations[i][0])
                    dp[j+1] = max(dp[j+1], dp[j] + stations[i][1]);
            }
        }
        for(i = 0; i <= num; ++i){
            if(dp[i] >= target){
                return i;
            }
        }
        return -1;
    }
};
