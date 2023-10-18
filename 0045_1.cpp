class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        vector<int> num(len, INT_MAX);
        num[0] = 0;
        int i = 0;
        int j , jumps = 0;
        for(i = 0; i < len; ++i){
            jumps = num[i] + 1;
            for(j=i+1; j <= i + nums[i]; ++j){
                if(j > len-1){
                    break;
                }
                num[j] = min(num[j], jumps);
            }

            
        }
        return num[len-1];

    }
};
