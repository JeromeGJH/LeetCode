class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        int mid = left + (right - left)/2;
        long res1, res2;
        while(left <= right){
            res1 = (long)mid * mid;
            res2 = res1 + mid + mid + 1;
            if(res1 == x){
                return mid;
            }
            if(res2 == x){
                return mid + 1;
            }
            if(x > res1 && x < res2){
                return mid;
            }
            if(x < res1){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
            mid = left + (right - left)/2;

        }
        return mid;
    }
};
