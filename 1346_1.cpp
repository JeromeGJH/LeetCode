class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        vector<int> positive, negative;
        int i = 0, j = 0;
        for(i = 0; i < arr.size(); ++i){
            if(arr[i] >= 0){
                positive.push_back(arr[i]);

            }else{
                negative.push_back(arr[i]);
            }
        }
        sort(positive.begin(), positive.end());
        sort(negative.rbegin(), negative.rend());
        vector<int> arr1 = positive;
        
        int length = arr1.size();
        int left, right, mid, target;
        for(i = 0; i < length; ++i){
            left = i + 1;
            right = length - 1;
            target = arr1[i] * 2;
            while(left <= right){
                mid = (left + right)/2;
                if(arr1[mid] == target){
                    return true;
                }
                if(arr1[mid] > target){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
        }

        arr1 = negative;
        length = arr1.size();
        for(i = 0; i < length; ++i){
            left = i + 1;
            right = length - 1;
            target = arr1[i] * 2;
            while(left <= right){
                mid = (left + right)/2;
                if(arr1[mid] == target){
                    return true;
                }
                if(arr1[mid] > target){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
        }
        return false;

    }
};
