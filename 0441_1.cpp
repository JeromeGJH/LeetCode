class Solution {
public:
    int arrangeCoins(int n) {
        int left = 1, right = n, mid = 1;
        long res;
        while(left < right){
            mid = left + (right - left)/2 + 1;
            res = ((long)mid * (mid + 1))/2;
            //cout << left << " " << right << " " << mid<<endl;
            if(res == n){
                return mid;
            }
            if(res > n){
                right = mid -1;
            }else{
                left = mid;
            }
        }
        return left;
    }
};
