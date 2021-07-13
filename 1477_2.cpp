class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int l = arr.size(), i = 0;
        if(l == 1){
            return -1;
        }
        int sum = arr[0];
        unordered_map<int, int> mp;
        mp[0] = -1;
        vector<int> dp(l, l+1);
        int tmp, res = l+1;
        mp[sum] = 0;
        if(arr[0] == target){
            dp[0] = 1;
        }
        for(i = 1; i < l ; ++i){
            sum += arr[i];
            if(mp.count(sum - target)){
                tmp = i - mp[sum - target];
                if(mp[sum-target] >= 0 && dp[mp[sum-target]] < l+1){
                    res = min(res , tmp + dp[mp[sum - target]]);
                }
                dp[i] = min(dp[i-1], tmp);
            }else{
                dp[i] = dp[i-1];
            }
            mp[sum] = i;
        }
        return res < l+1? res:-1;
    }
};
