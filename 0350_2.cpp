class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i, j, pivot = -1;
        vector<int> intersection;
        int left, right, mid;
        for(i = 0; i < nums1.size(); ++i){
            left = pivot+1;
            right = nums2.size() - 1;
            while(left <= right){
                mid =(left + right)/2;
                if(nums2[mid] == nums1[i]){
                    intersection.push_back(nums1[i]);
                    while(mid > pivot){
                        if(nums2[mid] == nums1[i]){
                            --mid;
                        }else{
                            break;
                        }
                    }
                    ++mid;
                    break;
                }
                if(nums2[mid] > nums1[i]){
                    right = mid -1;
                }else{
                    left = mid + 1;
                }
            }
            if(nums2[mid] == nums1[i]){
                pivot = mid;
            }
        }
        
        return intersection;
    }
};
