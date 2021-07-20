class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int l = arr.size(), i = 0, j = 0;
        vector<int> dp(l, 0);
        unordered_map<int, int> mp;
        int ans = 0;
        dp[0] = arr[0];
        for( i = 1; i < l; ++i){
            dp[i] = dp[i-1] ^ arr[i];
            if(dp[i] == 0){
                ans += i;
            }
        }
        for(i = 0; i<l-2; ++i){
            for(j = i+1; j < l; ++j){
                dp[j] ^= arr[i];
                if(j >= i+2 && dp[j] == 0){
                    ans += j - i - 1;
                }

            }
        }
        return ans;
    }
};
