class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int length = nums.size();
        int left = 1, right = length - 1, i, count;
        while(left < right){
            int mid = (left + right) / 2;
            count = 0;
            for(i = 0; i < length; ++i){
                if(nums[i] <= mid){
                    count += 1;
                }
            }
            if(count <= mid){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return right;
    }
};
