class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(startFuel >= target){
            return  0;
        }
        int num = stations.size();
        if(num == 0){
            if(startFuel < target)
                return  -1;
        }
        //cout << " here1";
        if(num == 1){
            if(startFuel < stations[0][0]){
                return -1;
            }
        }
        //cout << " here2";
        vector<vector<long>> dp(num, vector<long>(num+1, 0));
        int i  =0, j = 0;

        int ans = num;
        //cout << " here5" << endl;
        
        for(i = 0; i < num; ++i){
            dp[i][0] = startFuel;
            if(startFuel >= stations[i][0]){
                dp[i][1] = startFuel + stations[i][1];
            }
            for(j = 1; j <= i+1; ++j){
                for(int k = 0; k < i; ++k){
                    if(dp[k][j-1] >= stations[i][0]){
                        dp[i][j] = max(dp[i][j], dp[k][j-1] + stations[i][1]);
                    }
                }
                if(dp[i][j] >= target){
                    //cout << " i: " << i;
                    //cout << " j: " << j << endl;
                    ans = min(ans, j);
                    //cout << " ans: " << ans << endl;
                }
            }
            //cout << "last i: " << i << endl;
            //cout << dp[0][1] ;
            if(i == num-1){
                if(dp[i][i+1] < target){
                    //cout << " here6";
                    return -1;
                }
            }else{
                //cout << dp[i][i+1] << " " << stations[i+1][0] << endl;
                if(dp[i][i+1] < stations[i+1][0]){
                    //cout << " here7";
                    return -1;
                }
            }
            
        }
        
        return ans;
        

    }
};
