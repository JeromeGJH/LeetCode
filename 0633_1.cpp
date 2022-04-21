class Solution {
public:
    bool judgeSquareSum(int c) {
        int left = 0, right = sqrt(c), mid;
        long res;
        while(left <= right){
            res = (long)left * left + (long)right * right;
            if(res == c){
                return true;
            }
            if(res > c){
                --right;

            }else{
                ++left;
            }
        }
        return false;

    }
};
