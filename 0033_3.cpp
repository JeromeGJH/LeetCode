class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left, right, mid, n = nums.size();
        left = 0;
        right = n-1;
        while(left <= right){
            mid = (left + right)/2;
            if(target == nums[mid]){
                return mid;
            }
            if((nums[0] > nums[mid]) ^ (nums[0] > target) ^ (nums[mid] > target)){
                right= mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return -1;
    }
};
