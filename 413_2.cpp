class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int l = nums.size();
        if(l <= 2)
            return 0;
        int i = 0, j = 0, k = 0;
        int s = 2;
        int n = l-1;
        vector<int> dp(n, 0);
        int count = 0;
        for(i = 0; i < n; ++i){
            dp[i] = nums[i + 1] - nums[i];
        }

        // for(i = 0; i < n-1 ; ++i){
        //     j = i + 1;
        //     s = 2;
        //     while(j < n){
        //         //cout<< j << endl;
        //         if(dp[i] == dp[j]){
        //             cout << "1i = " << i << " ";
        //             cout << dp[i] << dp[i+1] <<endl;
        //         }else{
        //             break;
        //         }
        //         ++j;
        //     }
            
        //     if(dp[i] == dp[i+1]){
        //         cout << "2i = " << i << " ";
        //         cout << dp[i] << dp[i+1] <<endl;
        //     }
                
        // }


        for(i = 0; i < n - 1;){
            s = 2;
            j = i + 1;
            while(j < n){
                if(dp[i] == dp[j]){
                    ++j;
                    s += 1;
                }else{
                    break;
                }
            }
            
            for(k = 1; k <= s-2; ++k){
                 count += k;
            }
            i = j;
        }
        return count;

    }
};
