class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int i = 0;
        int j = len-1;
        int maxV = (len-2) * min(height[0], height[len-1]);
        int vol = 0;
        while(i < j){
            if(height[i] <= height[j]){
                vol = height[i] * (j-i);
                ++i;
            }else{
                vol = height[j] * (j - i);
                --j;
            }
            maxV = max(maxV, vol);
        }
        return maxV;
    }
};
