class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int l  =nums.size();
        unordered_map<int, int> mp;
        int i = 0, ans = 0, sum  =0;
        for(int i = 0; i < l; ++i){
            sum += nums[i] == 0?-1:1;
            if(sum == 0){
                ans = i+1;
                continue;
            }
            if(mp.count(sum) == 0){
                mp[sum] = i;
            }else{
                ans = max(ans, i - mp[sum]);
            }
        }
        return ans;
    }
};
