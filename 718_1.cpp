class Solution {
public:
    int findL(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(), l2 = nums2.size();
        int ans = 0, k = 0;
        int i = 0, j = 0;
        for(i = 0; i < l1; ++i){
            k = 0;
            for(j = 0 ; j < l2 && i+j < l1; ++j){
                if(nums1[i+j] == nums2[j]){
                    k += 1;
                }else{
                    k = 0;
                }
                ans = max(ans, k);
            }
        }
        return ans;
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans1 = findL(nums1, nums2);
        int ans2 = findL(nums2, nums1);
        return max(ans1, ans2);
    }

};
