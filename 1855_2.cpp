class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int left, right, mid=0;
        int i, j, res = 0;
        for(j = nums2.size()-1; j >= res; --j){
            for(i = min(j - res, (int)nums1.size() -1); i >= 0; --i){
                if(nums1[i] <= nums2[j]){
                    res = max(res, j - i);
                }else{
                    break;
                }
            }
        }
        return res;
    }
};
