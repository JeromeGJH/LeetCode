class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1){
            return nums;
        }

        int l = nums.size();

        vector<vector<int>> dp(l, vector<int>(k+1, 0));
        vector<int> res;

        //cout << "here"<<endl;

        int j = 1, i = 0;
        for(i = 0; i < l; ++i){
            dp[i][1] = nums[i];
        }

        //cout << "here" << endl;

        for(j = 2; j <= k; ++j){
            for(i = j - 1; i < l; ++i){
                if(nums[i] >= dp[i-j+1][j-1]){
                    dp[i-j+1][j] = nums[i];
                }else{
                    dp[i-j+1][j] = dp[i-j+1][j-1];
                }
            }

        }

        for(i = 0; i < l - k + 1; ++i){
            res.emplace_back(dp[i][k]);
        }
        return res;
    }
        
};
