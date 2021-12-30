class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i, j, k ;
        int sum = 0, diff = INT_MAX;

        for(j = 1; j < nums.size() - 1; ++j){
            i = 0;
            k = nums.size() - 1;
            while(i < j && k > j){
                sum = nums[i] + nums[j] + nums[k];
                if(sum > target){
                    --k;
                }
                if(sum == target){
                    return target;
                }
                if(sum < target){
                    ++i;
                }
                if(abs(diff) > abs(target - sum)){
                    diff = target - sum;
                }
            }
        }
        return target -diff;
    }
};
