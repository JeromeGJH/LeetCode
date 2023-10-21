class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1){
            return len;
        }
        int i = 0;
        unordered_map<int, bool> count;
        for(i = 0; i < len; ++i){
            if(count.count(nums[i]) == 0){
                count[nums[i]] = true;
            }
        }
        int res = 1;

        for(auto it = count.begin(); it != count.end(); ++it){
            int num = it->first;
            if(count.count(num+res) > 0){
                int l = 0;
                while(count.count(num) == 1){
                    l += 1;
                    ++num;
                }
                res = max(res, l);
            }

            
        }
        return res;


    }
};
