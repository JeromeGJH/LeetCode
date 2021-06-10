class Solution {
public:
    int shortestWay(string source, string target) {
        int l1 = source.length();
        int l2 = target.length();
        int count = 0;
        int i = 0, j = 0;
        int flag = j;
        while(j < l2){
            flag = j;
            while( i < l1){
                if(source[i] == target[j]){
                ++j;
                }
                ++i;
            }
            if(flag == j)
                return -1;
            count += 1;
            i = 0;
        }
        return count;
    }
}; //如果一轮匹配后j未发生变化则j不在source中，return -1.
