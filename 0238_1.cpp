class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        int i = 0;
        vector<int> dp1(len,1);
        vector<int> dp2(len,1);
        dp1[0] = nums[0];
        dp2[len-1] = nums[len-1];
        for(i = 1; i < len-1; ++i){
            dp1[i] = dp1[i-1] * nums[i];
            dp2[len-i-1] =dp2[len-i] * nums[len-i-1];
        }

        vector<int> res(len,1);
        res[0] = dp2[1];
        res[len-1] = dp1[len-2];
        for(i = 1; i<len-1; ++i){
            res[i] = dp1[i-1] * dp2[i+1];

        }
        return res;


        

    }
};
