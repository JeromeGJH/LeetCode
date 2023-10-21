class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int len  = tokens.size();
        int i = 0;
        int ans;
        std::stack<int> nums;
        int num1, num2, res;
        
        for(i = 0; i < len; ++i){
            if(tokens[i] == "+"){
                num2 = nums.top();
                nums.pop();
                num1 = nums.top();
                nums.pop();
                res = num1 + num2;
                nums.push(res);

                continue;
            }
            if(tokens[i] == "-"){
                num2 = nums.top();
                nums.pop();
                num1 = nums.top();
                nums.pop();
                res = num1 - num2;
                nums.push(res);
                continue;

            }
            if(tokens[i] == "*"){
                num2 = nums.top();
                nums.pop();
                num1 = nums.top();
                nums.pop();
                res = num1 * num2;
                nums.push(res);
                continue;

            }
            if(tokens[i] == "/"){
                num2 = nums.top();
                nums.pop();
                num1 = nums.top();
                nums.pop();
                res = num1 / num2;
                nums.push(res);
                continue;
            }
            nums.push(stoi(tokens[i]));
        }
        return nums.top();

    }
};
