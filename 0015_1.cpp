class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len =  nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if(nums[0] > 0 || nums[len-1] < 0){
            return res;
        }
        if(len == 3){
            if(nums[0] + nums[1] + nums[2] == 0){
                res.emplace_back(vector<int>({nums[0], nums[1], nums[2]}));
                return res; 
            }
        }
        
        
        int i, j, k, l, r, m, t, sum;
        for(i = 0; i < len-2; ++i){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            l = i+1;
            r = len-1;
            t = 0 - nums[i];
            while(l < r){
                sum = nums[l] + nums[r];
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
                    continue;
                }
                if(sum > t){
                    --r;
                    while(r > l && nums[r] == nums[r+1]){
                        --r;
                    }
                }else{
                    ++l;
                    while(l < r && nums[l] == nums[l-1]){
                        ++l;
                    }
                }
            }
        }
        return res;



    }
};
