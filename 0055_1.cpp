class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int i = 0,j;
        vector<int> tf(len, 0);
        tf[len-1] = 1;
        for(j= len-2; j >=0; --j){
            for(i = 1; i <= nums[j]; ++i){
                if(i+j >= len){
                    break;
                }
                if(tf[j+i] == 1){
                    tf[j] = 1;
                    break;
                }
            }
        }
        return tf[0] == 1;


    }
};
