class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int l = nums.size();
        if(l <= 2)
            return 0;
        int i = 0, j = 0, k = 0;
        int n = l-1;
        vector<int> dp(n, 0);
        int count = 0;
        for(i = 0; i < n; ++i){
            dp[i] = nums[i + 1] - nums[i];
        }
        // for(i = 0; i < n-1 ; ++i){
        //     if(dp[i] == dp[i+1]){
        //         cout << "i = " << i << " ";
        //         cout << dp[i] << dp[i+1] <<endl;
        //     }
                
        // }
        int s =2;

        for(i = 0; i < n; ++i){
            s = 2;
            j = i + 1;
            for(j; j < n; ++j){
                if(dp[i] == dp[j]){
                    cout << "i = " << i << " ";
                    cout << dp[i] << dp[i+1] <<endl;
                }
                if(dp[i] != dp[j]){
                    break;
                }
                s += 1;
            }
            
            for(k = 1; k <= s-2; ++k){
                count += k;
            }
            i = j;
        }
        return count;

    }
};














