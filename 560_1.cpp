class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int l = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        int i  = 0;
        int res = 0;
        for(i = 0; i  < l; ++i){
            sum += nums[i];
            
            if(mp.count(sum-k)){
                res += mp[sum-k];
            }
            if(mp.count(sum) == 0){
                mp[sum] = 1;
            }else{
                mp[sum] += 1;
            }
        }
        return res;

    }
};
