class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int l = nums.size();
        // diff, index, length
        unordered_map<int, int> index;
        int dp[l][l];
        int i = 0, j = 0, k = 0;
        int pre = 0;
        int ans = 0;
        for(i = 0; i < l; ++i){
            memset(dp[i], 0, sizeof(int) * l);
        }

        for( i = 0; i < l; ++i){
            for(j = i + 1; j < l; ++j){
                pre = nums[i] * 2 - nums[j];
                if(index.count(pre)){
                    dp[i][j] = max(dp[i][j], dp[index[pre]][i] + 1);
                    ans = max(ans, dp[i][j]);
                }
            }
            index[nums[i]] = i;
        }
        return ans + 2;
    }
};
