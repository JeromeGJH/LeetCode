class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h, left, right, n = citations.size();
        left = 0;
        right = n;
        while(left < right){
            h = (left + right) / 2 + 1;
            if(citations[n - h] >= h){
                left = h;
            }else{
                right = h - 1;
            }
        }
        return left;
    }
};
