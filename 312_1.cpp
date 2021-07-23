class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int l = nums.size();
        vector<vector<int>> dp(l+2, vector<int>(l+2, 0));
        vector<int> v;
        v.push_back(1);
        v.insert(v.begin()+1, nums.begin(), nums.end());
        v.push_back(1);
        int i = 0, j = 0, k, sum;
        for(j = 0; j <= l+1; ++j){
            for(i = j-2; i >= 0; --i){
                for(k = i+1; k < j; ++k){
                    dp[i][j] = max(dp[i][j], v[i]*v[j]*v[k] + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][l+1];
    }
};
