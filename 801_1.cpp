class Solution {
public:
    
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int l = nums1.size();
        int n1 = 0, s1 = 1;
        int s2 = l, n2 = l;
        int i = 0;
        for(i = 1; i < l; ++i){
            n2 = l;
            s2 = l;
            if(nums1[i] > nums1[i-1] && nums2[i] > nums2[i-1]){
                n2 = n1;
                s2 = min(s2, s1 +1);
            }
            if(nums1[i] > nums2[i-1] && nums2[i] > nums1[i-1]){
                n2 = min(n2, s1);
                s2 = min(s2, n1 +1);
            }
            n1 = n2;
            s1 = s2;
        }
        return min(n2, s2);
    }
};
