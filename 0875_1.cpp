class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mid, left = 1, right = *max_element(piles.begin(), piles.end());
        while(left < right){
            mid = (left + right) / 2;
            long times = 0;
            for(int nums : piles){
                times += (nums - 1) / mid + 1;
            }
            if(times > h){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return left;
    }
};
