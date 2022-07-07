class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int left = 1, right = maxSum;
        double preSum = 0, postSum = 0, sum = 0, mid;
        while(left < right){
            mid = floor((left + right) / 2) + 1;
            if(mid > index){
                preSum = (index + 1) * (mid - index + mid) / 2;
            }else{
                preSum = (1 + mid) * mid / 2 + index - mid + 1;
            }

            if(mid > n - index - 1){
                postSum = (n - index - 1) * (mid + mid - n + index) / 2;
            }else{
                postSum = mid * (mid - 1) / 2 + n - index - mid;
            }

            sum = preSum + postSum;
            if(sum == maxSum){
                return mid;
            }
            if(sum < maxSum){
                left = mid;
            }else{
                right = mid - 1;
            }
        }
        return left;

    }
};
