class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len =  nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if(nums[0] > 0 || nums[len-1] < 0){
            return res;
        }
        
        int i, l, r, t, sum;
        for(i = 0; i < len-2; ++i){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            l = i+1;
            r = len-1;
            t = 0 - nums[i];
            if(nums[l] > t/2 || nums[r] < t/2){
                continue;
            }
            while(l < r){
                sum = nums[l] + nums[r];
                if(sum >= t){
                    if(sum == t){
                        res.emplace_back(vector<int>({nums[i], nums[l], nums[r]}));
                        ++l;
                        while(l < r && nums[l] == nums[l-1]){
                            ++l;
                        }
                        --r;
                        while(r > l && nums[r] == nums[r+1]){
                            --r;
                        }
                    }else{
                        --r;
                    }
                }else{
                    ++l;
                }
            }
        }
        return res;



    }
};
