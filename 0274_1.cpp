class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater_equal<int>());
        int i = 0;
        int len = citations.size();
        for(i  =0; i < len; ++i){
            if(citations[i] < i+1){
                break;
            }
        }
        return i;

    }
};
