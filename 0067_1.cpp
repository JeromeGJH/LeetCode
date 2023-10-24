class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.length();
        int len2 = b.length();
        int res = 0, c = 0;
        string ans = "";
        int i = len1-1, j = len2-1;
        int num1, num2;
        //cout << a[0] - '0'<<endl;
        while(true){
            if(i == -1 && j == -1){
                if(c == 1){
                    ans = "1" + ans;
                }
                break;
            }
            if(i >= 0){
                num1 = a[i] - '0';
                --i;
            }else{
                num1 = 0;
            }
            if(j >= 0){
                num2 = b[j] - '0';
                --j;
            }else{
                num2 = 0;
            }
            res = num1 + num2 + c;
            c = res/2;
            res = res%2;
            //cout << num1 << " "<<num2<<endl;
            //cout << res << " "<<c<<endl;
            if(res == 0){
                ans = "0" + ans;
            }else{
                ans = "1" + ans;
            }
            
        }
        return ans;
    }
};
