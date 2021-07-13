class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int l = nums.size();
        unordered_map<int, int> mp;
        int i = 0, res = 0, rem = 0;
        mp[0] = 1;
        for(i = 0; i <l; ++i){
            rem = (rem + nums[i])%k;
            if(rem < 0){
                rem += k;
            }
            if(mp.count(rem)){
                res += mp[rem];
            }
            mp[rem] += 1;
        }
        return res;
    }
};
