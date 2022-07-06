class Solution {
public:
    int checkSum(vector<int>& arr, int v, int target, vector<int>& sums){
        int m = arr.size(), s;
        for(int i = 0; i < m; ++i){
            if(arr[i] > v){
                s = v * (m - i) + sums[i];
                return target - s;
            }
        }
        return target - sums[m];
    }

    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int m = arr.size();
        int left = 0, mid, right = arr[m-1], res;

        vector<int> sums = vector<int>(m+1, 0);
        for(int i = 1; i <= m; ++i){
            sums[i] = sums[i-1] + arr[i-1];
        }

        while(left < right){
            mid = (left + right) / 2 + 1;
            res = checkSum(arr, mid, target, sums);
            //cout << mid << "  " << res << endl;
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
        if(checkSum(arr, left, target, sums) + checkSum(arr, left+1, target, sums) <= 0){
            return left;
        }
        return left+1;

    }
};
