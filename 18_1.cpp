class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int len = nums.size();
        int t, s;
        if(len < 4)
            return res;

        sort(nums.begin(), nums.end());

        vector<int> entry(4, 0);
        
        int i, j, l, r;
        for(i = 0; i <= len-4; ++i){
            for(j = i+1; j <= len-3; ++j){
                if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target){
                    return res;
                }
                t = target - nums[i] - nums[j];
                l = j + 1;
                r = len-1;
                //cout <<i << " "<<j<< " "<<l<<" "<<r<<endl;
                while(l < r){
                    s = nums[l] + nums[r];
                    //cout<<l<<" "<<r<<endl;
                    if(s < t){
                        ++l;
                    }else{
                        if(s > t){
                            --r;
                        }else{
                            //cout<<"here3"<<endl;
                            entry[0] = nums[i];
                            entry[1] = nums[j];
                            entry[2] = nums[l];
                            entry[3] = nums[r];
                            res.push_back(entry);
                            
                            while(l+1 < r && nums[l] == nums[l+1]){
                                ++l;
                            }
                            ++l;
                            
                            while(r-1 > l && nums[r] == nums[r-1]){
                                --r;
                            }
                            --r;
                            //break;
                        }
                    }
                }
                while(j+1 <= len-3 && nums[j + 1] == nums[j]){
                    ++j;
                }
            }
            while(i+1 <= len-4 && nums[i + 1] == nums[i]){
                ++i;
            }
        }
        return res;
    }
};
