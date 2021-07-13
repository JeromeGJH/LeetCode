class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int l = nums.size();
        if(l == 1){
            return false;
        }
        unordered_map<int, int> mp;
        mp[0] = -1;
        int i = 0, j = 0;
        int sum = 0;
        for(i = 0; i < l; ++i){
            sum += nums[i];
            if(i >= 1 && sum % k == 0){
                return true;
            }
            for(j = 0; j*k <= sum; ++j){
                if(mp.count(sum - j*k) && i - mp[sum - j*k] >= 2){
                    return true;
                }
            }
            if(mp.count(sum) == 0){
                mp[sum] = i;
            }
            
        }
        return false;


    }
};
