class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = nums.size();
        if(l < 3){
            return l;
        }
        int slow = 2;
        int fast = 2;
        for(fast = 2; fast < l; ++fast){
            if(nums[fast] != nums[slow-2]){
                nums[slow] = nums[fast];
                ++slow;
                
            }
        }
        return slow;
    }
};
