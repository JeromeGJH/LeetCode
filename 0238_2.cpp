class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        int i = 0;
        vector<int> res(len,1);
        int R = nums[len-1];
        res[0] = nums[0];
        for(i = 1; i < len; ++i){
            res[i] = res[i-1] * nums[i];
        }
        res[len-1] = res[len-2];
        for(i = len-2; i>0; --i){
            res[i] = res[i-1] * R;
            R = R * nums[i];
        }
        res[0] = R;

        
        return res;


        

    }
};
