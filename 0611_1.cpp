class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left, right, mid;
        int i, j;
        int res = 0, target;
        for(i = 0; i < n-2; ++i){
            for(j = i + 1; j < n-1; ++j){
                target = nums[i] + nums[j] - 1;
                left = j+1;
                right = n-1;
                while(left < right){
                    mid = (left + right)/2 + 1;
                    if(nums[mid] <= target){
                        left = mid;
                    }else{
                        right = mid - 1;
                    }
                }
                if(nums[left] <= target){
                    res += left - j;
                }
            }
        }
        return res;
    }
};
