class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1){
            return nums;
        }

        int l = nums.size();
        
        vector<int> res;
        deque<int> index;


        int j = 1, i = 0;
        int max = nums[0];
        index.push_front(0);
        for(i = 1; i < k; ++i){
            while(!index.empty() && nums[i] > nums[index.back()]){
                index.pop_back();
            }
            index.push_back(i);
        }
        res.emplace_back(nums[index.front()]);

        for(i = k; i < l; ++i){
            if(index.front() < i - k + 1){
                index.pop_front();
            }
            while(!index.empty() && nums[i] > nums[index.back()]){
                index.pop_back();
            }
            index.push_back(i);
            res.emplace_back(nums[index.front()]);
        }
        
        return res;
    }
        
};
