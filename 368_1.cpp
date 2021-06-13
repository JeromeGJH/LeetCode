class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int l = nums.size();
        if(l == 1){
            return nums;
        }
        std::sort(nums.begin(), nums.end());
        unordered_map<int, int[2]> dp;
        int i = 0, j = 0;
        int ans[2] = {0};
        for(j = 0; j < l; ++j){
            dp[j][0] = -1;
            dp[j][1] = 1;
            for( i = 0; i < j; ++i){
                if(nums[j] % nums[i] == 0){
                    if(dp[j][1] < dp[i][1] + 1){
                        dp[j][0] = i;
                        dp[j][1] = dp[i][1] + 1;
                    }
                    if(ans[1] < dp[j][1]){
                        ans[0] = j;
                        ans[1] = dp[j][1];
                    }
                }
            }
        }
        vector<int> res;
        int iter = ans[0];
        while(1){
            res.push_back(nums[iter]);
            if(dp[iter][0] == -1)
                break;
            iter = dp[iter][0];
        }
        return res;
    }
};
