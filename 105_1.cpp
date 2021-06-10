class Solution {
public:
    int shortestWay(string source, string target) {
        int l1 = source.length();
        int l2 = target.length();
        // char str1[l1];
        // char str2[l2];
        // strcpy(str1, source.c_str());
        // strcpy(str2, target.c_str());
        int count = 0;
        int i = 0, j = 0;
        int flag = -1;
        while(j < l2){
            if(flag >= 0){
                while(i < flag){
                    if(source[i] == target[j]){
                        flag = -1;
                        ++j;
                        ++i;
                        break;
                    }
                    ++i;
                }
                if(flag >= 0)
                    return -1;
            }
            while(i < l1){
                if(flag >= 0){
                    if(source[i] == target[j]){
                        flag = -1;
                        ++j;
                    }
                }else{
                    if(source[i] == target[j])
                        ++j;
                    else
                        flag = i;
                }
                ++i;
            }
            count += 1;
            i = 0;
        }
        return count;
    }
};
