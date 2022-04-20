class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i, x;
        if(nums[0] >= nums.size()){
            return nums.size();
        }
        for(i = 1; i < nums.size(); ++i){
            x = nums.size() - i;
            if(nums[i] >= x && nums[i-1] < x){
                return x;
            }
        }
        return -1;

    }
};
