class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //cout << numbers[1];
        int left, right;
        int mid;
        int i = 0, t;
        for(i = 0; i < numbers.size(); ++i){
            t = target - numbers[i];
            left = i+1;
            right = numbers.size()-1;
            while(left <= right){
                mid = (left + right)/2;
                if(numbers[mid] == t){
                    return vector<int>{i+1, mid+1};
                }
                if(numbers[mid] > t){
                    right = mid -1;
                }else{
                    left = mid + 1;
                }
            }
        }
        return vector<int>{0, 0};
    }
};
