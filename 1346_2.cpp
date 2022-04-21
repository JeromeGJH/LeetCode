class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int i = 0, j = 0;
        int pivot;

        for(i = 0; i < arr.size(); ++i){
            if(arr[i] >= 0){
                pivot = i;
                break;
            }
        }

        int length = arr.size();
        int left, right, mid, target;

        for(i = pivot; i < length; ++i){
            left = i + 1;
            right = length - 1;
            target = arr[i] * 2;
            while(left <= right){
                mid = (left + right)/2;
                if(arr[mid] == target){
                    return true;
                }
                if(arr[mid] > target){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
        }

        for(i = pivot - 1; i >= 0; --i){
            left = 0;
            right = i - 1;
            target = arr[i] * 2;
            while(left <= right){
                mid = (left + right)/2;
                if(arr[mid] == target){
                    return true;
                }
                if(arr[mid] > target){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
        }
        return false;

    }
};
