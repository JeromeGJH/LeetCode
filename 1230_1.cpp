class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int l = prob.size();
        //cout << l;
        vector<vector<double>> dp(l, vector<double>(target+1, 0));
        //cout << "here1";
        dp[0][0] = 1 - prob[0];
        if(target > 0){
            dp[0][1] = prob[0];
        }
        int  i = 0, j = 0;
        for( i = 1; i < l; ++i){
            //cout << "i: "<<i <<" j: "<<j << " "<< endl;
            dp[i][0] = dp[i-1][0] * (1 - prob[i]);
            for(j = 1; j <= target && j <= i + 1; ++j){
                dp[i][j] = dp[i-1][j-1] * prob[i] + dp[i-1][j] * (1 - prob[i]);
            }
        }
        
        return dp[l-1][target];
    }
};
