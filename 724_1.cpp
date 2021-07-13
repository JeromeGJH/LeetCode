class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int l = nums.size(), i = 0;
        vector<int> L(l, 0 );
        vector<int> R(l, 0);
        for(i = 1; i < l; ++i){
            L[i] = L[i-1] + nums[i-1];
        }
        for(i = l-2; i >= 0; --i){
            R[i] = R[i+1] + nums[i+1];
        }
        for( i = 0 ; i < l; ++i){
            if(L[i] == R[i]){
                return i;
            }
        }
        return -1;

    }
};
