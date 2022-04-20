class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        int mid=(left + right)/2;
        int res = nums.size() - mid;;
        
        if(nums[0] >= nums.size()){
            return nums.size();
        }

        while(left < right){
            if(nums[mid] >= res){
                right = mid;
            }else{
                left = mid + 1;
            }
            mid = (left + right)/2;
            res = nums.size() - mid;
        }

        if(nums[mid] < res){
            return -1;
        }
        if(nums[mid-1] >= res){
            return -1;
        }
        return res;
    }
};
