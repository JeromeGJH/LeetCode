class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int left = 0, right = removable.size() - 1, mid;
        int i = 0, j = 0, l1 = s.length(), l2 = p.length();

        auto ifContained = [&](int k) -> bool{
            vector<int> state(l1, 1);
            for(i = 0; i <= k; ++i){
                state[removable[i]] = 0;
            }
            int flag = 0;
            for(j = 0; j < l2; ++j){
                for(i = flag; i < l1; ++i){
                    if(state[i] == 1 && s[i] == p[j]){
                        flag = i + 1;
                        break;
                    }
                }
                if(i >= flag){
                    return false;
                }
            }
            if(j == l2){
                return true;
            }
            return false;
        };



        while(left < right){
            mid = (left + right) / 2 + 1;
            if(ifContained(mid)){
                left = mid;
            }else{
                right = mid - 1;
            }
        }

        if(left == 0  && !ifContained(0)){
            return 0;
        }else{
            return left + 1;
        }

    }
};
