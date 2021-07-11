class Solution {
public:
    int findTheLongestSubstring(string s) {
        int l = s.length();
        int i = 0, ans = 0;
        int sum[5] = {0};
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        for(i = 0; i <l; ++i){
            if(s[i] == 'a'){
                sum[0] = (sum[0]+1)%2;
            }
            if(s[i] == 'e'){
                sum[1] = (sum[1]+1)%2;
            }
            if(s[i] == 'i'){
                sum[2] = (sum[2]+1)%2;
            }
            if(s[i] == 'o'){
                sum[3] = (sum[3]+1)%2;
            }
            if(s[i] == 'u'){
                sum[4] = (sum[4]+1)%2;
            }
            int tmp = sum[0]*10000 + sum[1]*1000 + sum[2]*100 + sum[3]*10 + sum[4];
            if(mp.count(tmp) == 0){
                mp[tmp] = i;
            }else{
                ans = max(ans, i - mp[tmp]);
            }
        }
        
        return ans;
    }
};
