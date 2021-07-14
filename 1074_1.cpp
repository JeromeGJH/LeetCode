class Solution {
public:
    int findSub(vector<int>& nums, int target){
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0, i = 0, res = 0;
        for(i = 0; i < nums.size(); ++i){
            sum += nums[i];
            if(mp.count(sum - target)){
                res += mp[sum - target];
            }
            mp[sum] += 1;
        }
        return res;

    }

    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        int i = 0, j = 0;
        for(i = 0; i < m; ++i){
            vector<int> sum(n, 0);
            for(j = i; j < m; ++j){
                for(int k = 0; k < n ; ++k){
                    sum[k] += matrix[j][k];
                }
                res += findSub(sum, target);
            }
        }
        return res;
    }
};
