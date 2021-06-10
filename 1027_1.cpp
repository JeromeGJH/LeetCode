class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int l = nums.size();
        // diff, index, length
        unordered_map<int, unordered_map<int, int>> dp;
        int i = 0, j = 0, k = 0;
        int diff = 0;
        int ans = 2;

        for( i = 1; i < l; ++i){
            for(j = 0; j < i; ++j){
                diff = nums[i] - nums[j];
                if(dp.count(diff) && dp[diff].count(j)){
                    dp[diff][i] = dp[diff][j] + 1;
                    ans = max(ans, dp[diff][i]);
                }else{
                    dp[diff][j] = 1;
                    dp[diff][i] = 2;
                }
            }
        }
        return ans;
    }
};
