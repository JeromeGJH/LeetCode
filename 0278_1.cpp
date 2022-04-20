// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(isBadVersion(1) == true){
            return 1;
        }
        int left=2, right=n;
        int mid = left + (right - left)/2;
        while(left <= right){
            if(isBadVersion(mid)){
                if(isBadVersion(mid-1)){
                    right = mid - 1;
                }else{
                    return mid;
                }
            }else{
                left = mid + 1;
            }
            mid = left + (right -left)/2;
        }
        return mid;
        
    }
};
