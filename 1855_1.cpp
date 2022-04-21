class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int left, right, mid=0;
        int i, res = 0;
        for(i = 0; i < nums1.size(); ++i){
            left = nums1[i] <= nums2[mid]? mid: i;
            right = nums2.size() - 1;
            while(left < right){
                mid = (left + right)/2 + 1;
                if(nums2[mid] >= nums1[i]){
                    res = max(res, mid - i);
                    left = mid;
                }else{
                    right = mid -1;
                }
            }
        }
        return res;
    }
};
