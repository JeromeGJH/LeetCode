class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1){
            return 0;
        }
        int start = 0;
        int j , jumps = 1, rightmost1 = nums[0], rightmost2 = 0;;
        while(1){
            if(rightmost1 >= len-1){
                break;
            }
            for(j = start+1; j <= rightmost1; ++j){
                rightmost2 = max(rightmost2, nums[j] + j);
            }
            jumps += 1;
            start = rightmost1;
            rightmost1 = rightmost2;
            rightmost2 = 0;
            
        }
        return jumps;

    }
};
