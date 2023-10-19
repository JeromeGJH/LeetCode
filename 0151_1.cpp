class Solution {
public:
    string reverseWords(string s) {
        int l1, l2, r1, r2;
        int len = s.length();
        l1 = len-1;
        string ans = "";
        int cnt =0;
        while(true){
            cnt = 0;
            while(l1 >= 0 && s[l1] == ' '){
                --l1;
            }
            if(l1 == -1){
                break;
            }
            
            while(l1 >= 0 && s[l1] != ' '){
                ++cnt;
                --l1;
            }
            cout << l1 << " "<< cnt << endl;
            ans = ans + s.substr(l1+1, cnt);
            if(l1 == -1){
                
                break;
            }

            while(l1 >= 0 && s[l1] == ' '){
                --l1;
            }
            if(l1 == -1){
                break;
            }else{
                ans = ans + " ";
            }
        }

        return ans;
    }
};
