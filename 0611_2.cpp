class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left, right, mid;
        int i, j;
        int res = 0, target, flag;
        for(i = 0; i < n-2; ++i){
            if(nums[i] == 0){
                continue;
            }
            left = i + 1;
            right = i + 2;
            for(left = i + 1; left < n-1; ++left){
                while(right < n && nums[right] < nums[i] + nums[left]){
                    ++right;
                }
                res += right - left - 1;
            }
        }
        return res;
    }
};
