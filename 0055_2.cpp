class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int i = 0,j;
        int pivot = len-1;
        for(j= len-2; j >=0; --j){
            if(j + nums[j] >= pivot){
                pivot = j;
            }
        }
        return pivot == 0;


    }
};
