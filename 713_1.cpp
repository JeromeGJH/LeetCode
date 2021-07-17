class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if( k == 0){
            return 0;
        }
        int  l = nums.size(), R  =0, L = -1;
        int pdt = 1, res = 0;
        for(R = 0; R < l; ++R){
            pdt *= nums[R];
            if(pdt < k){
                res += R -L;
            }else{
                while(L < R){
                    ++L;
                    pdt /= nums[L];
                    if(pdt < k){
                        res += R - L;
                        break;
                    }
                }
            }
        }
        return  res;

    }
};
