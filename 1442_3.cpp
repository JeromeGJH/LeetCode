class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int l = arr.size(), i = 0, j = 0;
        unordered_map<int, int> mp, total;
        mp[0] = 1;
        total[0] = -1;
        int ans = 0, res = 0;
        for(i = 0; i < l; ++i){
            res ^= arr[i];
            ans += mp[res] * (i-1) - total[res];
            mp[res] += 1;
            total[res] += i;
        }
        return ans;
    }
};
