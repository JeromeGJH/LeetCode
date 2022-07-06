class Solution {
public:
    int checkSum(vector<int>& arr, int v, int target){
        int m = arr.size(), s = 0;
        for(int i = 0; i < m; ++i){
            if(arr[i] > v){
                s += v * (m - i);
                return target - s;
            }
            s += arr[i];
        }
        return target - s;
    }

    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int m = arr.size();
        int left = 0, mid, right = arr[m-1], res;
        while(left < right){
            mid = (left + right) / 2 + 1;
            res = checkSum(arr, mid, target);
            cout << mid << "  " << res << endl;
            if(res == 0){
                return mid;
            }
            if(res < 0){
                right = mid - 1;
            }else{
                left = mid;
            }
        }
        if(left == arr[m-1]){
            return left;
        }
        if(checkSum(arr, left, target) + checkSum(arr, left+1, target) <= 0){
            return left;
        }
        return left+1;

    }
};
