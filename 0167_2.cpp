class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //cout << numbers[1];
        int left = 0, right = numbers.size()-1, sum;
        while(true){
            sum = numbers[left] + numbers[right];
            if(sum == target){
                return vector<int>{left+1, right+1};
            }
            if(sum > target){
                --right;
            }else{
                ++left;
            }
        }
        return vector<int>();
    }
};
