class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, res = INT_MAX;
        long sum = nums[0];
        while(left <= right){
            if(sum >= target){
                res = min(res, right - left + 1);
                sum -= nums[left];
                ++left;
            }else{
                ++right;
                if(right == nums.size()){
                    break;
                }
                sum += nums[right];
            }
        }
        return res == INT_MAX? 0:res;
    }
};
