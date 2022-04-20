class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(arr[0] > k){
            return k;
        }
        int left = 0, right = arr.size() -1;
        int mid, loss;
        while(left < right){
            mid = (left + right)/2 + 1;
            loss = arr[mid] - mid - 1;
            if(loss >= k){
                right = mid - 1;
            }else{
                left = mid;
            }
        }
        return k + left + 1;
    }
};
