class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left, right, mid, res = INT_MAX/2;
        vector<int>sum(nums.size(), 0);
        sum[0] = nums[0];
        int i;
        for(i = 1; i < nums.size(); ++i){
            sum[i] = sum[i-1] + nums[i];
        }
        int s = target;
        for(i = 0; i < nums.size(); ++i){
            left = i;
            right = min((int)nums.size()-1, left + res - 1);
            s = sum[left] - nums[left] + target;
            while(left < right){
                mid = (left + right)/2;
                if(sum[mid] == s){
                    res = min(res, mid -i+1);
                    break;
                }
                if(sum[mid] > s){
                    right = mid;
                    res = min(res, mid -i+1);
                }else{
                    left = mid + 1;
                }
            }
            if(sum[left] >= s){
                res = min(res, left - i + 1);
            }
        }
        return res == INT_MAX/2? 0:res;

    }
};
